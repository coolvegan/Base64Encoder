//
// Created by marco on 22.09.18.
//

#ifndef BITTEST3_BITBUFFER_H
#define BITTEST3_BITBUFFER_H


class BitBuffer {
private:
    unsigned int buffer;
    unsigned int buffer_size;
    unsigned int insert_position;
public:
    BitBuffer()
    {
        clear();
    }

    void push(unsigned int &number);
    unsigned int pop();
    bool full();

    int get(){
      return buffer;
    };

    int buffersize(){
        return this->buffer_size;
    }

    void clear()
    {
        buffer = 0;
        buffer_size = 0;
        insert_position = 3;
    }
};


#endif //BITTEST3_BITBUFFER_H
