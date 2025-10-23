#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
	int coeff;  
	int exp;    
	struct Term* next;
} Term;

Term* createPolynomial(int n, int* data) {
	if (n == 0) return NULL;
	
	Term* head = NULL;
	Term* tail = NULL;
	
	for (int i = 0; i < n; i++) {
		Term* newTerm = (Term*)malloc(sizeof(Term));
		newTerm->coeff = data[2 * i];
		newTerm->exp = data[2 * i + 1];
		newTerm->next = NULL;
		
		if (head == NULL) {
			head = newTerm;
			tail = newTerm;
		} else {
			tail->next = newTerm;
			tail = newTerm;
		}
	}
	
	return head;
}

Term* addPolynomials(Term* poly1, Term* poly2) {
	Term dummy = {0, 0, NULL};  
	Term* tail = &dummy;
	
	while (poly1 != NULL && poly2 != NULL) {
		Term* newTerm = (Term*)malloc(sizeof(Term));
		
		if (poly1->exp < poly2->exp) {
			newTerm->coeff = poly1->coeff;
			newTerm->exp = poly1->exp;
			poly1 = poly1->next;
		} else if (poly1->exp > poly2->exp) {
			newTerm->coeff = poly2->coeff;
			newTerm->exp = poly2->exp;
			poly2 = poly2->next;
		} else {
			newTerm->coeff = poly1->coeff + poly2->coeff;
			newTerm->exp = poly1->exp;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		
		if (newTerm->coeff != 0) {
			newTerm->next = NULL;
			tail->next = newTerm;
			tail = newTerm;
		} else {
			free(newTerm);  
		}
	}
	
	Term* remaining = (poly1 != NULL) ? poly1 : poly2;
	while (remaining != NULL) {
		Term* newTerm = (Term*)malloc(sizeof(Term));
		newTerm->coeff = remaining->coeff;
		newTerm->exp = remaining->exp;
		newTerm->next = NULL;
		
		tail->next = newTerm;
		tail = newTerm;
		remaining = remaining->next;
	}
	
	return dummy.next;
}

Term* subtractPolynomials(Term* poly1, Term* poly2) {
	Term dummy = {0, 0, NULL}; 
	Term* tail = &dummy;
	
	while (poly1 != NULL && poly2 != NULL) {
		Term* newTerm = (Term*)malloc(sizeof(Term));
		
		if (poly1->exp < poly2->exp) {
			newTerm->coeff = poly1->coeff;
			newTerm->exp = poly1->exp;
			poly1 = poly1->next;
		} else if (poly1->exp > poly2->exp) {
			newTerm->coeff = -poly2->coeff;
			newTerm->exp = poly2->exp;
			poly2 = poly2->next;
		} else {
			newTerm->coeff = poly1->coeff - poly2->coeff;
			newTerm->exp = poly1->exp;
			poly1 = poly1->next;
			poly2 = poly2->next;
		}
		
		if (newTerm->coeff != 0) {
			newTerm->next = NULL;
			tail->next = newTerm;
			tail = newTerm;
		} else {
			free(newTerm);  
		}
	}
	
	while (poly1 != NULL) {
		Term* newTerm = (Term*)malloc(sizeof(Term));
		newTerm->coeff = poly1->coeff;
		newTerm->exp = poly1->exp;
		newTerm->next = NULL;
		
		tail->next = newTerm;
		tail = newTerm;
		poly1 = poly1->next;
	}
	
	while (poly2 != NULL) {
		Term* newTerm = (Term*)malloc(sizeof(Term));
		newTerm->coeff = -poly2->coeff;
		newTerm->exp = poly2->exp;
		newTerm->next = NULL;
		
		tail->next = newTerm;
		tail = newTerm;
		poly2 = poly2->next;
	}
	
	return dummy.next;
}

void printPolynomial(Term* poly) {
	if (poly == NULL) {
		printf("0");
		return;
	}
	
	int first_term = 1;
	Term* current = poly;
	
	while (current != NULL) {
		int coeff = current->coeff;
		int exp = current->exp;
		
		if (!first_term) {
			if (coeff > 0) {
				printf("+");
			} else {
				printf("-");
				coeff = -coeff;
			}
		} else {
			if (coeff < 0) {
				printf("-");
				coeff = -coeff;
			}
			first_term = 0;
		}
		
		if (exp == 0) {
			printf("%d", coeff);  
		} else if (coeff == 1 && exp == 1) {
			printf("x");          
		} else if (coeff == 1) {
			printf("x^%d", exp);  
		} else if (exp == 1) {
			printf("%dx", coeff);
		} else {
			printf("%dx^%d", coeff, exp);
		}
		
		current = current->next;
	}
	printf("\n");
}

void freePolynomial(Term* poly) {
	while (poly != NULL) {
		Term* temp = poly;
		poly = poly->next;
		free(temp);
	}
}

int main() {
	int n, m, t;
	scanf("%d %d %d", &n, &m, &t);
	
	int* data1 = (int*)malloc(2 * n * sizeof(int));
	int* data2 = (int*)malloc(2 * m * sizeof(int));
	
	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &data1[i]);
	}
	for (int i = 0; i < 2 * m; i++) {
		scanf("%d", &data2[i]);
	}
	
	Term* poly1 = createPolynomial(n, data1);
	Term* poly2 = createPolynomial(m, data2);
	
	Term* result;
	if (t == 0) {
		result = addPolynomials(poly1, poly2);
	} else {
		result = subtractPolynomials(poly1, poly2);
	}
	
	printPolynomial(result);
	freePolynomial(poly1);
	freePolynomial(poly2);
	freePolynomial(result);
	free(data1);
	free(data2);
	
	return 0;
}
