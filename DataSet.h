#pragma once
#ifndef DATASET_H
#define DATASET_H

#define NAUGHT 0x00FACADE
#include <Arduino.h>

class LoggerWrap;

//typename type;


template<typename type> class DataSet
{
public:
	DataSet(); 
	//	Default Constructor
	//	Pre: none
	//	Post: Initializes the data set to a size 0 array.
	DataSet(int in_size);
	//	Parameterized constructor
	//	Pre: None
	//	Post: Initializes the data set size to the parameter in_size
	~DataSet();
	//	Decon
	type get_data(int in_pos);
	//	Gets data from the array.
	//	Pre: Self initialized.
	//	Post: returns data in the array from parameter position in_pos
	int get_pos();
	//	Gets the current array position
	//	Pre: Self initialized
	//	Post: returns the active array position.
	int get_size();
	//	Gets the size of the array
	//	Pre: Self initialized
	//	Post: returns the max number of elements that can be stored in the array.
	void set_data(type in_data);
	//	Assigns the parameter in_data to the active array position
	//	Pre: Self initialized, matching type
	//	Post: puts the parameter in_data at the active array position
private:
	void fillArray();
	//	Fills array data with Naught
	//	Pre: Self initialized
	//	Post: Fills all array points with 0x00FACADE
	void circlePos();
	//	Resets array pos to zero once filled.
	//	Pre: Self initialized
	//	Post: Pos = 0 after checks.
	type * data;
	int size;
	int pos;
};



template<typename type> DataSet<type>::DataSet()
{
	size = 0;
	pos = 0;
	data = new type[size];
}


template<typename type> DataSet<type>::DataSet(int in_size)
{
	size = in_size;
	pos = 0;
	data = new type[size];
	fillArray();
}


template<typename type> DataSet<type>::~DataSet()
{

}


template<typename type> type DataSet<type>::get_data(int in_pos)
{
	return data[in_pos];
}


template<typename type> int DataSet<type>::get_pos()
{
	return pos;
}


template<typename type> int DataSet<type>::get_size()
{
	return size;
}


template<typename type> void DataSet<type>::set_data(type in_data)
{
	if ((pos < size) && (pos >= 0))
	{
		data[pos] = in_data;
		pos++;
		if (pos >= size)
			circlePos();
	}
}


template<typename type> void DataSet<type>::fillArray()
{
	int tempPos = 0;
	while (tempPos < size)
	{
		data[tempPos] = NAUGHT;
		tempPos++;
	}
}


template<typename type> void DataSet<type>::circlePos()
{
	pos = 0;
}


#endif // !DATASET_H

