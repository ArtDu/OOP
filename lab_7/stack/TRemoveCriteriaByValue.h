#ifndef TSTACKS_TREMOVECRITERIABYVALUE_H_
#define TSTACKS_TREMOVECRITERIABYVALUE_H_

#include "TRemoveCriteria.h"

template<class T>
class TRemoveCriteriaByValue: public TRemoveCriteria<T> {
public:
	TRemoveCriteriaByValue(double value) :
			_value(value) {
	}
	;
	bool isIt(T& obj) override {
		return _value == obj->Square();
	}
private:
	double _value;
};
#endif /* TSTACKS_TREMOVECRITERIABYVALUE_H_ */
