//
// Created by marco on 22.09.18.
//

#include "BitBuffer.h"

void BitBuffer::push(unsigned int &number)
{
    unsigned int tmp = 0;
    tmp = (number&3);
    tmp = tmp << buffer_size;
    buffer = (this->buffer | (tmp&insert_position));
    insert_position *=4;
    buffer_size+=2;
    number = (number >> 2);
}

unsigned int BitBuffer::pop() {
    if (buffersize()> 0)
    {
        buffer_size -= 2;
        insert_position /= 4;
        unsigned int tmp = this->buffer;
        buffer = (buffer >> 2);
        return (tmp & 3);
    }
}

bool BitBuffer::full() {
    return (this->buffer_size==6);
}
