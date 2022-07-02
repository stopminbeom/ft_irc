#include "Server.hpp"

using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char **argv) {
	if (argc =! 3) {
		cerr << "Error: bad arguments" << endl;
		return 1;
	}
	for (int i = 0; argv[1][i]; i++) {
		if (!isdigit(argv[1][i])) {
			cerr << "Error: invalid character in port" << endl;
			return 1;
		}
	}
	// 2. 인자를 확인한 이후 파싱하여 (port & password) 서버에 넣어준다.
	// 3. 셋업 쪽의 파싱은 내가 담당한다.
	// 4. 이후는 .... 부탁한다!!!!!!
}