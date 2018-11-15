#ifndef LISTS_TREMOVECRITERIAALL_H_
#define LISTS_TREMOVECRITERIAALL_H_

#include "TRemoveCriteria.h"
template<class T>
class TRemoveCriteriaAll: public TRemoveCriteria<T> {
public:
	TRemoveCriteriaAll() {	}
	;
	bool isIt(T& obj) override {
		return true;
	}
private:
};

#endif /* LISTS_TREMOVECRITERIAALL_H_ */
