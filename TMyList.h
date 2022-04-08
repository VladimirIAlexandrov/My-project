#ifndef TMYLIST_H
#define TMYLIST_H

#pragma once

template<class TMyIListValue>
class TMyListItem {
public:
	TMyListItem* next;
	TMyIListValue Value;
	TMyListItem() {
		next = nullptr;
	}

	~TMyListItem() {
		next = nullptr;
	}
}
;


template<typename TMyIListValue>
class TMyList
{
  protected:
	  TMyListItem<TMyIListValue>* root;
  public:
	TMyList() {
		root = nullptr;
	}
	~TMyList() {
		while (this->root != nullptr) {
			auto p = root;
			root = root->next;
			delete p;
		}
		root = nullptr;
	}
	TMyListItem<TMyIListValue>* Add(void)
	{
		int n = 0;
		TMyListItem<TMyIListValue>* Item = new TMyListItem<TMyIListValue>();
		if (this->root == nullptr) {
			this->root = Item;
		}
		else {
			auto p = this->root;
			while (p->next != nullptr) {
				p = p->next;
			}
			p->next = Item;
		}	return Item;
	}

	//TMyListItem* Get(int n);
	TMyListItem<TMyIListValue>* operator[](int n)
	{
		auto p = this->root;
		for (int i = n; i > 0 && p != nullptr; i--, p = p->next) {
			if (i == 1) return p;
		}
		return nullptr;
	}

	int GetSize(void)
	{
		int n = 0;
		auto p = this->root;
		while (p != nullptr) {
			n++;
			p = p->next;
		}
		return n;
	}

	void Delete(int n)
	{
		TMyListItem* p = this->root;
		TMyListItem* prev = nullptr;
		for (int i = 0; p != nullptr; i++, prev = p, p = p->next) {
			if (i == n && p != nullptr) {
				prev->next = p->next;
				delete p;
			}
		}
		root = nullptr;
	}

};


#endif