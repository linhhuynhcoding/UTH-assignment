#include "Website.h"
#include <iostream>

#pragma once
class WebBrowser
{
private:
	Website* head;
	Website* tail;
	Website* current;
	public:
	WebBrowser() {
		head = nullptr;
		tail = nullptr;
		current = nullptr;
	}
	
	void goTo(Website *targetWebsite) {
		if (head == nullptr) {
			head = targetWebsite;
			tail = head;
			current = head;
			return;
		}
		if (head == tail) {
			tail = targetWebsite;
			head->setNext(tail);
			tail->setBack(head);
			current = tail;
			return;
		}
		targetWebsite->setBack(tail);
		tail->setNext(targetWebsite);
		tail = targetWebsite;
		current = tail;
	}

	void back_() {
		if (current->getBack() == nullptr) {
			cout << "Day la trang dau, khong the quay lai!\n";
			return;
		}
		current = current->getBack();
		current->increaseAccessTimes();
		cout << "hien tai dang o : " << current->getAddress() << "\n";
	}
	
	void forward_() {
		if (current->getNext() == nullptr) {
			cout << "Day la trang cuoi, khong the tien len!\n";
			return;
		}
		current = current->getNext();
		current->increaseAccessTimes();
		cout << "hien tai dang o : " << current->getAddress() << "\n";

	}

	void history() {
		if (head == nullptr) {
			cout << "Lich su trong!!!\n";
		}
		Website* p = head;
		while (p != nullptr) {
			cout << p->getAddress() << "\n";
			p = p->getNext();
		}
		return;
	}

	void clearHistory() {
		head = nullptr;
		tail = nullptr;
		current = nullptr;
		cout << "Da xoa lich su!!\n";
	}

	void thongke() {
		if (head == nullptr) {
			cout << "Lich su trong!!!\n";
		}
		cout << "THONG KE: \n";
		Website* p = head;
		while (p != nullptr) {
			cout << "\t" << p->getAddress() << "\t: " << p->getAccessTimes()  << "\n";
			p = p->getNext();

		}
		return;
	}
};

