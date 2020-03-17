
struct big {
	char name;
	int n;
	int *cifras;
};
typedef struct big Big;
typedef struct big *BigAP;
Big *creaBig(int n);
void imprimeBig(Big *a);
Big *copiaBig(Big *a);
Big *sumaBig(Big *a, Big *b);
Big *restaBig(Big *a, Big *b);
Big *multiBig(Big *a, Big *b);
