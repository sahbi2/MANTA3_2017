// Generated by gencpp from file manta/Echo.msg
// DO NOT EDIT!


#ifndef MANTA_MESSAGE_ECHO_H
#define MANTA_MESSAGE_ECHO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace manta
{
template <class ContainerAllocator>
struct Echo_
{
  typedef Echo_<ContainerAllocator> Type;

  Echo_()
    : profondeur(0.0)  {
    }
  Echo_(const ContainerAllocator& _alloc)
    : profondeur(0.0)  {
    }



   typedef double _profondeur_type;
  _profondeur_type profondeur;




  typedef boost::shared_ptr< ::manta::Echo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::manta::Echo_<ContainerAllocator> const> ConstPtr;

}; // struct Echo_

typedef ::manta::Echo_<std::allocator<void> > Echo;

typedef boost::shared_ptr< ::manta::Echo > EchoPtr;
typedef boost::shared_ptr< ::manta::Echo const> EchoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::manta::Echo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::manta::Echo_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace manta

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'manta': ['/home/pi/my_catkin_ws/src/manta/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::manta::Echo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::manta::Echo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::manta::Echo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::manta::Echo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::manta::Echo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::manta::Echo_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::manta::Echo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b2e0694a5f1544fb7c77b695e4945a13";
  }

  static const char* value(const ::manta::Echo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb2e0694a5f1544fbULL;
  static const uint64_t static_value2 = 0x7c77b695e4945a13ULL;
};

template<class ContainerAllocator>
struct DataType< ::manta::Echo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "manta/Echo";
  }

  static const char* value(const ::manta::Echo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::manta::Echo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64  profondeur\n\
";
  }

  static const char* value(const ::manta::Echo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::manta::Echo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.profondeur);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Echo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::manta::Echo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::manta::Echo_<ContainerAllocator>& v)
  {
    s << indent << "profondeur: ";
    Printer<double>::stream(s, indent + "  ", v.profondeur);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MANTA_MESSAGE_ECHO_H
