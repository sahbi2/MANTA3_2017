// Generated by gencpp from file manta/CmdMotors.msg
// DO NOT EDIT!


#ifndef MANTA_MESSAGE_CMDMOTORS_H
#define MANTA_MESSAGE_CMDMOTORS_H


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
struct CmdMotors_
{
  typedef CmdMotors_<ContainerAllocator> Type;

  CmdMotors_()
    : startMotors(false)
    , motorLeft(0)
    , motorRight(0)  {
    }
  CmdMotors_(const ContainerAllocator& _alloc)
    : startMotors(false)
    , motorLeft(0)
    , motorRight(0)  {
    }



   typedef uint8_t _startMotors_type;
  _startMotors_type startMotors;

   typedef uint8_t _motorLeft_type;
  _motorLeft_type motorLeft;

   typedef uint8_t _motorRight_type;
  _motorRight_type motorRight;




  typedef boost::shared_ptr< ::manta::CmdMotors_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::manta::CmdMotors_<ContainerAllocator> const> ConstPtr;

}; // struct CmdMotors_

typedef ::manta::CmdMotors_<std::allocator<void> > CmdMotors;

typedef boost::shared_ptr< ::manta::CmdMotors > CmdMotorsPtr;
typedef boost::shared_ptr< ::manta::CmdMotors const> CmdMotorsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::manta::CmdMotors_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::manta::CmdMotors_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::manta::CmdMotors_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::manta::CmdMotors_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::manta::CmdMotors_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::manta::CmdMotors_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::manta::CmdMotors_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::manta::CmdMotors_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::manta::CmdMotors_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3ee8ef12710d8d370ae71ac748657306";
  }

  static const char* value(const ::manta::CmdMotors_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3ee8ef12710d8d37ULL;
  static const uint64_t static_value2 = 0x0ae71ac748657306ULL;
};

template<class ContainerAllocator>
struct DataType< ::manta::CmdMotors_<ContainerAllocator> >
{
  static const char* value()
  {
    return "manta/CmdMotors";
  }

  static const char* value(const ::manta::CmdMotors_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::manta::CmdMotors_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool  startMotors\n\
uint8 motorLeft\n\
uint8 motorRight\n\
";
  }

  static const char* value(const ::manta::CmdMotors_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::manta::CmdMotors_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.startMotors);
      stream.next(m.motorLeft);
      stream.next(m.motorRight);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct CmdMotors_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::manta::CmdMotors_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::manta::CmdMotors_<ContainerAllocator>& v)
  {
    s << indent << "startMotors: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.startMotors);
    s << indent << "motorLeft: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motorLeft);
    s << indent << "motorRight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.motorRight);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MANTA_MESSAGE_CMDMOTORS_H
