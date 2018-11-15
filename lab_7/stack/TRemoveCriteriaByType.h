#ifndef LIST_TREMOVECRITERIABYTYPE_H_
#define LIST_TREMOVECRITERIABYTYPE_H_


#include "TRemoveCriteria.h"
template<class T>
class TRemoveCriteriaByType: public TRemoveCriteria<T> {
public:
	TRemoveCriteriaByType(double value) :
			_value(value) {
	}
	;
	bool isIt(T& obj) override {
		return _value == obj->getType();
	}
private:
	char _value;
};


#endif /* LIST_TREMOVECRITERIABYTYPE_H_ */
