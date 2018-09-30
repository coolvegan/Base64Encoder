//
// Created by marco on 23.09.18.
//

#ifndef BITTEST3_BASE64ENCODE_H
#define BITTEST3_BASE64ENCODE_H


#include "Dependencies/BitBuffer.h"
#include <vector>
#include <string>
#include "Dependencies/Constants.h"

class Base64Encode {
private:
    BitBuffer bitbuffer;
    std::vector<unsigned char> list;
    std::string input;
    unsigned int octet_to_convert;
    unsigned int last_iteratation_buffer_size;
    void run(std::string &plain_data);
    void add_full_buffer_to_new_char();
    void move_bits_from_octet_to_buffer();
    void move_bits_from_buffer_to_octet();
    void add_the_equal_sign_if_neccessary();
public:
    Base64Encode(std::string &plain_data);
    std::vector<unsigned char> &converted_vector();
    std::string converted();
};


#endif //BITTEST3_BASE64ENCODE_H
