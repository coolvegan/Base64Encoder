//
// Created by marco on 23.09.18.
//

#include "Base64Encode.h"

Base64Encode::Base64Encode(std::string &plain_data) {
    run(plain_data);
}

void Base64Encode::run(std::string &plain_data) {

      for (auto convertible : plain_data) {

        octet_to_convert = 0;

        last_iteratation_buffer_size = 0;

        add_full_buffer_to_new_char();

        last_iteratation_buffer_size = bitbuffer.buffersize();

        octet_to_convert = static_cast<unsigned char>(convertible);

        move_bits_from_octet_to_buffer();

        move_bits_from_buffer_to_octet();

        list.push_back(alphabet[octet_to_convert]);
    }

    last_iteratation_buffer_size = bitbuffer.buffersize();

    octet_to_convert = 0;

    move_bits_from_buffer_to_octet();

    list.push_back(alphabet[octet_to_convert]);

    add_the_equal_sign_if_neccessary();
}

void Base64Encode::add_full_buffer_to_new_char() {
    if (bitbuffer.buffersize() == b64_bit_length)
    {
        list.push_back(alphabet[bitbuffer.get()]);
        bitbuffer.clear();
    }
}

void Base64Encode::move_bits_from_octet_to_buffer() {
    for (int k = 0; k < (last_iteratation_buffer_size+2); k = k + 2) {
        bitbuffer.push(octet_to_convert);
    }
}

void Base64Encode::move_bits_from_buffer_to_octet() {
    for (int l = 0; l < last_iteratation_buffer_size; l=l+2) {
        unsigned int shift_position = 0;
        shift_position = bitbuffer.pop();
        shift_position = shift_position << (b64_bit_length - last_iteratation_buffer_size + l);
        octet_to_convert = octet_to_convert | shift_position;
    }
}

void Base64Encode::add_the_equal_sign_if_neccessary() {
    for (int j = last_iteratation_buffer_size; j < 6; j+=2) {
        list.push_back('=');
    }
}

std::vector<unsigned char> &Base64Encode::converted_vector() {
    return list;
}

std::string Base64Encode::converted() {
    std::string str(list.begin(), list.end());
    return str;
}

