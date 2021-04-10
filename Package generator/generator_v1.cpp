#ifndef SAFE_AND_LOW_LATENCY_MIDDLEWARE_MESSAGE_H_20170502_1122_
#define SAFE_AND_LOW_LATENCY_MIDDLEWARE_MESSAGE_H_20170502_1122_

#include <cstdlib>
#include <stdint.h>

#include <fstream>
#include <iostream>
#include <iomanip>

#include <stdlib.h>
#include <time.h>

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
};

typedef struct _pkg_head pkg_head_def;

typedef struct
{
  size_t buff_length;
  char* buff_ptr;
} buff_item_def;

#endif

using namespace std;

int main()
{
  fstream file;
  file.open("msg.txt",ios::out | ios::binary);

  int num;
  cout << "enter message quantity: ";
  cin >> num;
  pkg_head_def data[num];

  srand((unsigned)time(NULL));

  for (int i = 0; i < num; ++i)
  {
    data[i].seq_num = i;
    data[i].topic_length = (1 + rand() % 65535);
    //heartbeat once every ten times
    if ( (i+1)%10 == 0)
    {
      data[i].msg_length = 0;
    }
    else
    {
      data[i].msg_length = (0 + rand() % 65536);
    }
    //72 for H, 77 for M
    if (data[i].msg_length == 0)
    {
      data[i].msg_type = 'H';
    }
    else
    {
        data[i].msg_type = 'M';
    }

    cout << data[i].seq_num << " ";
    cout << data[i].topic_length << " ";
    cout << data[i].msg_length << " ";
    cout << data[i].msg_type << endl;
  }

  if (file.fail())
  {
    cout << "fail\n";
  }
  else
  {
    for (int i = 0; i < num; ++i)
    {
      file << setw(16) << setfill('0') << hex << data[i].seq_num;
      file << setw(4) << setfill('0') << hex << data[i].topic_length;
      file << setw(4) << setfill('0') << hex << data[i].msg_length;
      file << setw(2) << setfill('0') << hex << (int)data[i].msg_type;

      /*
      for (int j = 0; j < data[i].topic_length; ++j)
      {
        file << hex << (int)'t';
      }
      for (int k = 0; k < data[i].msg_length; ++k)
      {
        file << hex << (int)'m';
      }
      */

      file << endl;
    }
    file.close();
  }

  return 0;
}
