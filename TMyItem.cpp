#include "TMyItem.h"

TMyItem::TMyItem() {
	this->i = 0;
	this->s = "";
}

TMyItem::TMyItem(int i, std::string s) {
	this->i = i;
	this->s = s;
}

TMyItem::~TMyItem() {
	this->i = 0;
	this->s = "";
}

