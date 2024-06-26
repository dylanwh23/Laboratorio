/*
 * File:   String.h
 * Author: igui
 *
 * Created on 29 de mayo de 2011, 06:53 PM
 */

#ifndef STRING_H
#define STRING_H
#include "interfaces/OrderedKey.h"
#include <iostream>
using namespace std;

class String: public OrderedKey {

public:
	string nick;
	String();
	String(string key);
	virtual ~String();
	ComparisonRes compare(OrderedKey *k) const;
};

#endif	/* PROG4_STRING_H */
