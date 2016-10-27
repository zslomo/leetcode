#include<unordered_map>
#include<stdlib.h>
#include<utility>
using namespace std;
class LRUlist {
public:
	int key;
	LRUlist *next;
	LRUlist *pre;
	LRUlist(int k) :key(k), next(NULL), pre(NULL) {}
};
class LRUCache {
private:
	unordered_map<int, int>cache;
	LRUlist *head;
	LRUlist *rear;
	int size = 0;
public:
	LRUCache(int capacity) {
		size = capacity;
		head = new LRUlist(0);
		rear = head;
	}

	int get(int key) {
		auto a = cache.find(key);
		if (a != cache.end()) {
			return a->second;
		}
		else return -1;
	}

	void set(int key, int value) {
		auto a = cache.find(key);
		if (a != cache.end()) {
			Listkeynode_delete(key);
			List_insert(key);
			a->second = value;
		}
		else {
			Add(key, value);
		}
	}
private:
	void List_insert(int key) {
		LRUlist *p = new LRUlist(key);
		rear->next = p;
		p->pre = rear;
		rear = p;
	}
	int Listheadnode_delete() {
		LRUlist *p = head->next;
		if (p == rear) {
			rear = head;
			head->next = NULL;
		}
		else {
			head->next = p->next;
			p->next->pre = head;
		}
		int key = p->key;
		free(p);
		return key;
	}
	void Listkeynode_delete(int key) {
		LRUlist *p = head;
		while (p->key != key) p = p->next;
		if (p == rear) {
			p->pre->next = NULL;
		}
		else {
			p->pre->next = p->next;
			p->next->pre = p->pre;
		}
			free(p);
	}
	void Add(int key, int value) {
		if (cache.size() == size) {
			int key = Listheadnode_delete();
			cache.erase(key);
		}
		cache[key] = value;
		List_insert(key);
	}
};

int main(int argc, char*argv[]) {
	LRUCache *test = new LRUCache(2);
	test->set(2, 1);
	test->set(2, 2);
	test->get(2);
	test->set(1, 1);
	
	test->set(4, 1);
	test->get(2);
	system("pause");

}