#pragma once

template <class T>
class List {
protected:
	int mSize;
	virtual void add(const T& obj) = 0;
	virtual void insert(const T& obj, int location) = 0;
	virtual void setAt(const T& obj, int location) = 0;
	virtual T& get(int location) const = 0;
	virtual void remove(const T& obj) = 0;
	virtual void removeAt(int location) = 0;
	virtual int indexOf(const T& obj) const = 0;

	virtual T& operator[](int location) {
		return get(location);
	}

	int size() {
		return mSize;
	}

	bool isEmpty() {
		return mSize == 0;
	}
};