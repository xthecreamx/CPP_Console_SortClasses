#ifndef SWAP_DEFINED
#define SWAP_DEFINED
template<class type> void Swap(type& x, type& y)
{
	type temp = x;
	x = y;
	y = temp;
};
#endif
