#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

class SingleInstance
{
public:
	static SingleInstance & getInstance();
	void print();
	void set(int i);
private:
	static SingleInstance * pSI;
	int value;
	SingleInstance();
	SingleInstance(const SingleInstance &) = delete;
	SingleInstance(const SingleInstance &&) = delete;
	SingleInstance & operator = (const SingleInstance &) = delete;
	SingleInstance & operator = (const SingleInstance &&) = delete;
	~SingleInstance();
	class Garbo { public: Garbo(); ~Garbo(); };
	static Garbo gc;
};

#endif //SINGLEINSTANCE_H
