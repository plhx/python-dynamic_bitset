#include <sstream>
#include <string>
#include <boost/dynamic_bitset.hpp>
#include <boost/python.hpp>

namespace py = boost::python;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(
    resize_, boost::template dynamic_bitset<>::resize, 1, 2
);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(
    set_, boost::template dynamic_bitset<>::set, 0, 2
);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(
    reset_, boost::template dynamic_bitset<>::reset, 0, 1
);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(
    flip_, boost::template dynamic_bitset<>::flip, 0, 1
);

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(
    test_set_, boost::template dynamic_bitset<>::test_set, 1, 2
);

static void append_(boost::dynamic_bitset<> &self, py::object obj) {
    py::stl_input_iterator<boost::dynamic_bitset<>::block_type> begin(obj);
    py::stl_input_iterator<boost::dynamic_bitset<>::block_type> end;
    self.append(begin, end);
}

static std::string __repr___(const boost::dynamic_bitset<> &self) {
    std::ostringstream ss;
    ss << self;
    return ss.str();
}

static py::long_ __int___(const boost::dynamic_bitset<> &self) {
    return py::long_(__repr___(self), 2);
}

BOOST_PYTHON_MODULE(dynamic_bitset) {
    py::class_<boost::dynamic_bitset<> >("dynamic_bitset",
        py::init<py::optional<
            boost::dynamic_bitset<>::size_type,
            unsigned long
        > >()
    )
    .def(
        py::init<py::optional<
            const std::string &,
            std::string::size_type,
            std::string::size_type
        > >()
    )
    .def(py::init<const boost::dynamic_bitset<> &>())
    .def("swap",
        static_cast<void (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<> &
        )>(&boost::dynamic_bitset<>::swap)
    )
    .def("resize",
        static_cast<void (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type, bool
        )>(&boost::dynamic_bitset<>::resize),
        resize_()
    )
    .def("clear",
        static_cast<void (boost::dynamic_bitset<>::*)(
            void
        )>(&boost::dynamic_bitset<>::clear)
    )
    .def("pop_back",
        static_cast<void (boost::dynamic_bitset<>::*)(
            void
        )>(&boost::dynamic_bitset<>::pop_back)
    )
    .def("push_back",
        static_cast<void (boost::dynamic_bitset<>::*)(
            bool
        )>(&boost::dynamic_bitset<>::push_back)
    )
    .def("append",
        static_cast<void (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::block_type
        )>(&boost::dynamic_bitset<>::append)
    )
    .def("append", append_)
    .def("__iand__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        )>(&boost::dynamic_bitset<>::operator&=),
        py::return_internal_reference<>()
    )
    .def("__ior__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        )>(&boost::dynamic_bitset<>::operator|=),
        py::return_internal_reference<>()
    )
    .def("__ixor__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        )>(&boost::dynamic_bitset<>::operator^=),
        py::return_internal_reference<>()
    )
    .def("__isub__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        )>(&boost::dynamic_bitset<>::operator-=),
        py::return_internal_reference<>()
    )
    .def("__ilshift__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<>::size_type
        )>(&boost::dynamic_bitset<>::operator<<=),
        py::return_internal_reference<>()
    )
    .def("__irshift__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<>::size_type
        )>(&boost::dynamic_bitset<>::operator>>=),
        py::return_internal_reference<>()
    )
    .def("__lshift__",
        static_cast<boost::dynamic_bitset<> (boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<>::size_type
        ) const>(&boost::dynamic_bitset<>::operator<<)
    )
    .def("__rshift__",
        static_cast<boost::dynamic_bitset<> (boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<>::size_type
        ) const>(&boost::dynamic_bitset<>::operator>>)
    )
    .def("set",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type, bool
        )>(&boost::dynamic_bitset<>::set),
        py::return_internal_reference<>(),
        set_()
    )
    .def("reset",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type
        )>(&boost::dynamic_bitset<>::reset),
        py::return_internal_reference<>(),
        reset_()
    )
    .def("flip",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type
        )>(&boost::dynamic_bitset<>::flip),
        py::return_internal_reference<>(),
        flip_()
    )
    .def("test",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type
        ) const>(&boost::dynamic_bitset<>::test)
    )
    .def("test_set",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type, bool
        )>(&boost::dynamic_bitset<>::test_set),
        test_set_()
    )
    .def("all",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            void
        ) const>(&boost::dynamic_bitset<>::all)
    )
    .def("any",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            void
        ) const>(&boost::dynamic_bitset<>::any)
    )
    .def("none",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            void
        ) const>(&boost::dynamic_bitset<>::none)
    )
    .def("__invert__",
        static_cast<boost::dynamic_bitset<> (boost::dynamic_bitset<>::*)(
            void
        ) const>(&boost::dynamic_bitset<>::operator~)
    )
    .def("count",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::count)
    )
    .def("__setitem__",
        static_cast<boost::dynamic_bitset<> &(boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type, bool
        )>(&boost::dynamic_bitset<>::set),
        py::return_internal_reference<>()
    )
    .def("__getitem__",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type
        ) const>(&boost::dynamic_bitset<>::operator[])
    )
    .def("to_ulong",
        static_cast<unsigned long (boost::dynamic_bitset<>::*)(
            void
        ) const>(&boost::dynamic_bitset<>::to_ulong)
    )
    .def("__len__",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::size)
    )
    .def("num_blocks",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::num_blocks)
    )
    .def("max_size",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::max_size)
    )
    .def("empty",
        static_cast<bool (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::empty)
    )
    .def("capacity",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::capacity)
    )
    .def("reserve",
        static_cast<void (boost::dynamic_bitset<>::*)(
            boost::dynamic_bitset<>::size_type
        )>(&boost::dynamic_bitset<>::reserve)
    )
    .def("shrink_to_fit",
        static_cast<void (boost::dynamic_bitset<>::*)(
            void
        )>(&boost::dynamic_bitset<>::shrink_to_fit)
    )
    .def("is_subset_of",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        ) const>(&boost::dynamic_bitset<>::is_subset_of)
    )
    .def("is_proper_subset_of",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        ) const>(&boost::dynamic_bitset<>::is_proper_subset_of)
    )
    .def("intersects",
        static_cast<bool (boost::dynamic_bitset<>::*)(
            const boost::dynamic_bitset<> &
        ) const>(&boost::dynamic_bitset<>::intersects)
    )
    .def("find_first",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(void) const>(&boost::dynamic_bitset<>::find_first)
    )
    .def("find_next",
        static_cast<boost::dynamic_bitset<>::size_type (
            boost::dynamic_bitset<>::*
        )(boost::dynamic_bitset<>::size_type) const>(
            &boost::dynamic_bitset<>::find_next
        )
    )
    .def("__eq__",
        static_cast<bool (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator==)
    )
    .def("__ne__",
        static_cast<bool (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator!=)
    )
    .def("__lt__",
        static_cast<bool (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator<)
    )
    .def("__le__",
        static_cast<bool (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator<=)
    )
    .def("__gt__",
        static_cast<bool (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator>)
    )
    .def("__ge__",
        static_cast<bool (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator>=)
    )
    .def("__and__",
        static_cast<boost::dynamic_bitset<> (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator&)
    )
    .def("__or__",
        static_cast<boost::dynamic_bitset<> (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator|)
    )
    .def("__xor__",
        static_cast<boost::dynamic_bitset<> (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator^)
    )
    .def("__sub__",
        static_cast<boost::dynamic_bitset<> (*)(
            const boost::dynamic_bitset<> &, const boost::dynamic_bitset<> &
        )>(boost::operator-)
    )
    .def("__repr__", __repr___)
    .def("__int__", __int___);
}
