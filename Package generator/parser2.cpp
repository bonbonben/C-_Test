#ifndef SAFE_AND_LOW_LATENCY_MIDDLEWARE_MESSAGE_H_20170502_1122_
#define SAFE_AND_LOW_LATENCY_MIDDLEWARE_MESSAGE_H_20170502_1122_

#include <cstdlib>
#include <stdint.h>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

//----------------------------------------------------------
// * there are 3 parts of a package for sending message.
//   1. package head
//   2. topic name
//   3. message
//----------------------------------------------------------

struct _pkg_head
{
  // all big endian integer.
  // sequence number of message.
  uint64_t seq_num;
  // length of topic name.
  uint16_t topic_length;
  // length of message
  uint16_t msg_length;
  // type of message.
  // 'M': message.
  // 'H': heartbeat.
  char msg_type;

  std::string topic;
  std::string message;
};

typedef struct _pkg_head pkg_head_def;

typedef struct
{
  size_t buff_length;
  char* buff_ptr;
} buff_item_def;

#endif

using namespace std;

uint64_t swap_8bytes(uint64_t &value)
{
  value = (value << 56) |
          ((value<<40) & 0x00FF000000000000ull) |
          ((value<<24) & 0x0000FF0000000000ull) |
          ((value<<8) & 0x000000FF00000000ull) |
          ((value>>8) & 0x00000000FF000000ull) |
          ((value>>24) & 0x0000000000FF0000ull) |
          ((value>>40) & 0x000000000000FF00ull) |
          (value >> 56);
  return value;
}

uint16_t swap_2bytes(uint16_t value)
{
  value = (value >> 8) | (value << 8);
  return value;
}

int main()
{
  FILE *fp;
  fpos_t pos;
  int seqnosize = 8;
  int tlengthsize = 2;
  int mlengthsize = 2;
  int mtypesize = 1;
  int headersize = 13;
  int tlength;
  int mlength;

  fp = fopen("test", "rb");
/*
  // Move the pointer to the end of the file
  if(fseek(fp, 0, SEEK_END))
  {
    // File seek error.
    return -1;
  }
  long fileLength = 0;
  fileLength = ftell(fp);
  // Move the pointer back to the beginning of the file
  fseek(fp, 0, SEEK_SET);
*/
  unsigned char buff[30];

  char c;
  c = fgetc(fp);

  if (!fp)
  {
    return 1;
  }
  else
  {
    pos = 0x00;
    while (fscanf(fp, "%c", &c) != EOF)
    {
      int l = 0;

      fsetpos(fp, &pos);
      fread(buff, sizeof(char), 30, fp);

      for(int i = 0 ; i < headersize; i++)
      {
        printf("%02x", buff[i]);
      }
      l += headersize;

      tlength = buff[8] * 10 + buff[9] * 1;
      mlength = buff[10] * 10 + buff[11] * 1;

      for (int i = l; i < l + tlength + mlength; ++i)
      {
        printf("%c", buff[i]);
      }

      l += tlength;
      l += mlength;

      printf("\n");

      pos += l;
    }
  }

  return 0;
}
