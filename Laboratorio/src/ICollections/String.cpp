#include "String.h"
#include "interfaces/OrderedKey.h"


String::String() {
	// TODO Auto-generated constructor stub

}

String::String(string nick) {
	this->nick = nick;

}

String::~String() {
	// TODO Auto-generated destructor stub
}


ComparisonRes String::compare(OrderedKey *k) const {
	String *key = dynamic_cast<String *>(k);
	 if (key->nick == this->nick) {

		return ComparisonRes::EQUAL;
	} else {
		if (key->nick > this->nick) {
			return ComparisonRes::GREATER;
		} else {
			return ComparisonRes::LESSER;
		}
	}

}
