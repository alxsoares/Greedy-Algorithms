#include <iostream>
#include <algorithm>
#include <queue>
#define SENTINAL '\0'
using namespace std;

/*  Given a character and the amount of it in a text, find its code.
    Input:  a 5     Output: a: 1100
            b 9             b: 1101
            c 12            c: 100 */
struct node {
	char character;
	int freq;
	struct node *left;
	struct node *right;

	node(char chas, int fr) {
        character = chas;
        freq = fr;
        left = NULL;
        right = NULL;
	};
};

typedef node node;

class nodeCompare {
	public:
    bool operator() (node *a, node *b) {
        return (a->freq > b->freq);
    }
};

/*  Print heap and nodes */
void print_heap(node *head, std::string path) {
	if(!head) return;

	if(head->character !=SENTINAL)
		cout << head->character << " code is " << path << endl;

	print_heap(head->left, path + "0");
	print_heap(head->right, path + "1");
}

int main() {
	priority_queue <node *, vector<node *>, nodeCompare> minHeap;

	/* Fill queue */
	minHeap.push(new node('a', 5));
	minHeap.push(new node('b', 9));
	minHeap.push(new node('c', 12));
	minHeap.push(new node('d', 13));
	minHeap.push(new node('e', 16));
	minHeap.push(new node('f', 45));

	/* Iterate till heap size is 1 */
	while(minHeap.size() > 1) {
		node *min1 = minHeap.top();
		minHeap.pop();

		node *min2 = minHeap.top();
		minHeap.pop();

		node * new_node = new node(SENTINAL, min1->freq + min2->freq);
		new_node->left = min1;
		new_node->right = min2;
		minHeap.push(new_node);
	}

	print_heap(minHeap.top(), string(""));
	return 0;
}
