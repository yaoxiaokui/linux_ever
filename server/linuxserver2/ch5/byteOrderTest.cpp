#include <iostream>

using namespace std;

void byteOrder()
{
	union{
		short value;
		char bytes[sizeof(short)];
	}testValue;

	testValue.value = 0x1234;

	if(testValue.bytes[0] == 0x34 && testValue.bytes[1] == 0x12){
		cout << "小端存储" << endl;
	}
	else if(testValue.bytes[0] == 0x12 && testValue.bytes[1] == 0x34){
		cout << "大端存储" << endl;
	}

}


int main(int argc, char *argv[])
{
	byteOrder();
	
	return 0;
}
