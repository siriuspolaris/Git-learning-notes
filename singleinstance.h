#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

class SingleInstance
{
public:
	static SingleInstance & getInstance();
	void print();
	void set(int i);
private:
	SingleInstance();
	SingleInstance(const SingleInstance &) = delete;
	SingleInstance(const SingleInstance &&) = delete;
	SingleInstance & operator = (const SingleInstance &) = delete;
	SingleInstance & operator = (const SingleInstance &&) = delete;
	~SingleInstance();
	class Garbo { public: Garbo(); ~Garbo(); };
	static Garbo gc;
	static SingleInstance * pSI;
	int value;
};

#endif //SINGLEINSTANCE_H
