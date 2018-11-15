#ifndef LISTS_TREMOVECRITERIA_H_
#define LISTS_TREMOVECRITERIA_H_
#include <memory>

template<class T>
class TRemoveCriteria {
public:
	virtual bool isIt(T& obj) = 0;
	virtual ~TRemoveCriteria() {};
private:
};

#endif /* LISTS_TREMOVECRITERIA_H_ */
