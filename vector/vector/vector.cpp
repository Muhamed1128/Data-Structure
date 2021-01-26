#include <iostream>
using namespace std;
template<class t>
class vector
{
	t* arr;
	int capa;
	int length;
public:
	vector();
	vector(int len,t item);
	vector(int s);
	vector(const vector<t>& v);
	vector<t>& operator=(const vector<t>&);
	t& operator[](int pos);
	bool empty();
	t& at(int pos);
	int size();
	void resize(int len);
	int capacity();
	void clear();
	void shrink_to_fit();
	void push_back(t new_item);
	void pop_back();
	void insert(int pos, t item);
	void erase(int pos);
	void erase(int pos1, int pos2);
	t& front();
	t& back();
	t begin();
	t end();
	~vector();
};


int main()
{
	vector<int>v(4);

	for (int i = 0; i < 4; i++)
	{
		v.at(i)=i;
	}
	cout << v[2];
	
}


template<class t>
vector<t>::vector(int s)
{
	if (s > 0)
	{
		capa = s;
		length = s;
		arr = new t[s];

		for (int i = 0; i < length; i++)
		{
			arr[i] = 0;
		}
	}
}

template<class t>
vector<t>::vector(const vector<t>& v)
{
	length = v.length;
	capa = v.capa;
	arr = new t[length];
	for (int i = 0; i <length; i++)
		arr[i] = v.arr[i];
}

template<class t>
vector<t>& vector<t>::operator=(const vector<t>&)
{
	delete[] arr;
	length = v.length;
	capa = v.capa;
	arr = new t[length];
	for (int i = 0; i < length; i++)
		arr[i] = v.arr[i];
	return *this;
}

template<class t>
vector<t>::vector()
{
	arr = new t[1];
	capa = 1;
	length = 0;
}

template<class t>
vector<t>::vector(int len, t item)
{
	if (len > 0)
	{
		capa = len;
		length = len;
		arr = new t[len];

		for (int i = 0; i < length; i++)
		{
			arr[i] = item;
		}
	}
}

template<class t>
t& vector<t>::operator[](int pos)
{
	return arr[pos];
}

template<class t>
bool vector<t>::empty()
{
	return length==0;
}

template<class t>
t& vector<t>::at(int pos)
{
	if (0 > pos || pos > length)
		cout << "out of the range" << endl;
	else
		return arr[pos];
}

template<class t>
int vector<t>::size()
{
	return length;
}

template<class t>
void vector<t>::resize(int len)
{
	if(len>length)
	{
		for (int i = length; i < len; i++)
		{
			arr[i] = 0;
		}
	}
	length = len;
}

template<class t>
int vector<t>::capacity()
{
	return capa;
}

template<class t>
void vector<t>::clear()
{
	length = 0;
	capa = 0;
	delete[] arr;
}

template<class t>
void vector<t>::shrink_to_fit()
{
	capa = length;
	t* temp = new t[length];
	for (int i = 0; i < length; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	temp = NULL;
	delete[] temp;
	
}

template<class t>
void vector<t>::push_back(t new_item)
{
	if (length > 3)
		capa = length + length / 2;
	else
		capa = length;
	t* temp = new t[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = arr[i];
	}
	temp[length] = new_item;
	length++;
	delete[] arr;
	arr = temp;
	temp = NULL;
	delete[]temp;
}

template<class t>
void vector<t>::pop_back()
{
	t* temp = new t[length -1];
	for (int i = 0; i < length-1; i++)
	{
		temp[i] = arr[i];
	}
	length--;
	delete[] arr;
	arr = temp;
	temp = NULL;
	delete[]temp;
}

template<class t>
void vector<t>::insert(int pos, t item)
{
	if (0 > pos || pos > length)
		cout << "out of the range" << endl;
	else
	{
		for (int i = length; i > pos; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[pos] = item;
		if (length > 3)
			capa = length + length / 2;
		else
			capa = length;
		length++;
	}
}

template<class t>
void vector<t>::erase(int pos)
{
	if (empty())
		cout << "is empty" << endl;
	else if (0 > pos || pos > length)
		cout << "out of the range" << endl;
	else
	{
		t* temp = new t[length - 1];
		int j = 0;
		for (int i = 0; i < length; i++)
		{
			if (i == pos)
				continue;
			temp[j] = arr[i];
			j++;
		}
		delete[]arr;
		arr = temp;
		temp = NULL;
		delete[] temp;
		length--;
	}
}

template<class t>
void vector<t>::erase(int pos1, int pos2)
{
	if (empty())
	{
		cout << "is empty" << endl;
	}
	else if ((0 > pos1 || pos1 > length)&&(0 > pos2 || pos2 > length))
		cout << "out of the range" << endl;
	else
	{
		if (pos1 > pos2)
		{
			pos1 = pos1 + pos2;
			pos2 = pos1 - pos2;
			pos1 = pos1 - pos2;
		}
		t* temp = new t[length-((pos2-pos1)-1)];
			int j = 0;
		for (int i = 0; i < length; i++)
		{
			if (i >= pos1 && i <= pos2)
			{
				continue;
			}

			else if (i < pos1)
			{
				temp[j] = arr[i];
				j++;
			}
			else
			{
				temp[j] = arr[i];
				j++;
			}		
		}
		delete[]arr;
		arr = temp;
		temp = NULL;
		delete[] temp;
		length = length - ((pos2 - pos1) + 1);
	}
}

template<class t>
t& vector<t>::front()
{
	return arr[0];
}

template<class t>
t& vector<t>::back()
{
	return arr[length - 1];
}

template<class t>
t vector<t>::begin()
{
	t* ptr = &arr[0];
	return ptr;
}



template<class t>
t vector<t>::end()
{
	t* ptr = &arr[length + 1];
	return ptr;
}

template<class t>
vector<t>::~vector()
{
	delete[] arr;
}

