#ifndef SAFE_AND_LOW_LATENCY_MIDDLEWARE_MESSAGE_H_20170502_1122_
#define SAFE_AND_LOW_LATENCY_MIDDLEWARE_MESSAGE_H_20170502_1122_

#include <cstdlib>
#include <stdint.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

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

int main()
{
  ofstream file("test", ios::binary);

  int num;
  cout << "enter message quantity: ";
  cin >> num;
  pkg_head_def data[num];

  for (int i = 0; i < num; ++i)
  {
    data[i].seq_num = i;

    string str;
    stringstream ss;
    ss << i;
    ss >> str;

    data[i].topic = "topic";
    data[i].topic += str;
    data[i].message = "";
    data[i].topic_length = data[i].topic.size();
    //heartbeat once every ten times
    if ( (i+1)%10 == 0)
    {
      data[i].msg_length = 0;
      data[i].msg_type = 'H';
    }
    else
    {
      data[i].message += "message";
      data[i].message += str;

      data[i].msg_length = data[i].message.size();
      data[i].msg_type = 'M';
    }

    cout << data[i].seq_num << " ";
    cout << data[i].topic_length << " ";
    cout << data[i].msg_length << " ";
    cout << data[i].msg_type << " ";
    cout << data[i].topic << " ";
    cout << data[i].message << endl;
  }

  if (file.fail())
  {
    cout << "fail\n";
  }
  else
  {
    for (int i = 0; i < num; ++i)
    {
      uint64_t buf [3] = {data[i].seq_num,data[i].topic_length,data[i].msg_length};
      file.write((char *) &buf[0], sizeof(uint64_t));
      file.write((char *) &buf[1], sizeof(uint16_t));
      file.write((char *) &buf[2], sizeof(uint16_t));

      //first message: 00 00 00 00 00 00 00 00 06 00 08 00 4D 74 6F 70 69 63 30 6D 65 73 73 61 67 65 30 0A
      file << data[i].msg_type;
      file << data[i].topic;
      file << data[i].message << endl;
    }
    file.close();
  }

  return 0;
}
