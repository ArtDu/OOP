#ifndef TSTACKS_TREMOVECRITERIAALL_H_
#define TSTACKS_TREMOVECRITERIAALL_H_

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

#endif /* TSTACKS_TREMOVECRITERIAALL_H_ */
