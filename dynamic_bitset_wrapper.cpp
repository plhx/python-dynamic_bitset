#include <string>
#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/operators.hpp>
#include <boost/python/wrapper.hpp>
#include <boost/python/module.hpp>
#include <boost/python/detail/wrap_python.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/operators.hpp>

namespace python = boost::python;

BOOST_PYTHON_MODULE(dynamic_bitset){
	python::class_<boost::dynamic_bitset<> >("dynamic_bitset",python::init<size_t,long>())
		.def(python::init<const std::string &>())
		.def("resize",&boost::dynamic_bitset<>::resize)
		.def("clear",&boost::dynamic_bitset<>::clear)
		.def("push_back",&boost::dynamic_bitset<>::push_back)
		.def(python::self & python::self)
		.def(python::self | python::self)
		.def(python::self ^ python::self)
		.def(python::self - python::self)
		.def(python::self << long())
		.def(python::self >> long())
		.def("set",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(size_t,bool))&boost::dynamic_bitset<>::set,python::return_internal_reference<>())
		.def("set",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)())&boost::dynamic_bitset<>::set,python::return_internal_reference<>())
		.def("reset",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(size_t))&boost::dynamic_bitset<>::reset,python::return_internal_reference<>())
		.def("reset",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)())&boost::dynamic_bitset<>::reset,python::return_internal_reference<>())
		.def("flip",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(size_t))&boost::dynamic_bitset<>::flip,python::return_internal_reference<>())
		.def("flip",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)())&boost::dynamic_bitset<>::flip,python::return_internal_reference<>())
		.def("test",&boost::dynamic_bitset<>::test)
		.def("any",&boost::dynamic_bitset<>::any)
		.def("none",&boost::dynamic_bitset<>::none)
		.def("__setitem__",(boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(size_t,bool))&boost::dynamic_bitset<>::set,python::return_internal_reference<>())
		.def("__getitem__",(bool (boost::dynamic_bitset<>::*)(size_t) const)&boost::dynamic_bitset<>::operator[])
		.def("to_ulong",&boost::dynamic_bitset<>::to_ulong)
		.def("__len__",&boost::dynamic_bitset<>::size)
		.def("__nonzero__",&boost::dynamic_bitset<>::any)
		.def("size",&boost::dynamic_bitset<>::size)
		.def("num_blocks",&boost::dynamic_bitset<>::num_blocks)
		.def("max_size",&boost::dynamic_bitset<>::max_size)
		.def("empty",&boost::dynamic_bitset<>::empty)
		.def("is_subset_of",&boost::dynamic_bitset<>::is_subset_of)
		.def("is_proper_subset_of",&boost::dynamic_bitset<>::is_proper_subset_of)
		.def("find_first",&boost::dynamic_bitset<>::find_first)
		.def("find_next",&boost::dynamic_bitset<>::find_next)
		.def(~python::self)
		.def(python::self == python::self)
		.def(python::self <= python::self)
		.def(python::self >= python::self)
		.def(python::self < python::self)
		.def(python::self > python::self)
	;
}

