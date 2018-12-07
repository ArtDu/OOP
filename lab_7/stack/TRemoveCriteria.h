#ifndef STACKS_TREMOVECRITERIA_H_
#define STACKS_TREMOVECRITERIA_H_
#include <memory>

template<class T>
class TRemoveCriteria {
public:
	virtual bool isIt(T& obj) = 0;
	virtual ~TRemoveCriteria() {};
private:
};

#endif /* STACKS_TREMOVECRITERIA_H_ */
