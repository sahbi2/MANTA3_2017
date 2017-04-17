; Auto-generated. Do not edit!


(cl:in-package manta-msg)


;//! \htmlinclude CmdMotors.msg.html

(cl:defclass <CmdMotors> (roslisp-msg-protocol:ros-message)
  ((startMotors
    :reader startMotors
    :initarg :startMotors
    :type cl:boolean
    :initform cl:nil)
   (motorLeft
    :reader motorLeft
    :initarg :motorLeft
    :type cl:fixnum
    :initform 0)
   (motorRight
    :reader motorRight
    :initarg :motorRight
    :type cl:fixnum
    :initform 0))
)

(cl:defclass CmdMotors (<CmdMotors>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CmdMotors>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CmdMotors)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name manta-msg:<CmdMotors> is deprecated: use manta-msg:CmdMotors instead.")))

(cl:ensure-generic-function 'startMotors-val :lambda-list '(m))
(cl:defmethod startMotors-val ((m <CmdMotors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:startMotors-val is deprecated.  Use manta-msg:startMotors instead.")
  (startMotors m))

(cl:ensure-generic-function 'motorLeft-val :lambda-list '(m))
(cl:defmethod motorLeft-val ((m <CmdMotors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:motorLeft-val is deprecated.  Use manta-msg:motorLeft instead.")
  (motorLeft m))

(cl:ensure-generic-function 'motorRight-val :lambda-list '(m))
(cl:defmethod motorRight-val ((m <CmdMotors>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:motorRight-val is deprecated.  Use manta-msg:motorRight instead.")
  (motorRight m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CmdMotors>) ostream)
  "Serializes a message object of type '<CmdMotors>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'startMotors) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motorLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motorRight)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CmdMotors>) istream)
  "Deserializes a message object of type '<CmdMotors>"
    (cl:setf (cl:slot-value msg 'startMotors) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motorLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motorRight)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CmdMotors>)))
  "Returns string type for a message object of type '<CmdMotors>"
  "manta/CmdMotors")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CmdMotors)))
  "Returns string type for a message object of type 'CmdMotors"
  "manta/CmdMotors")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CmdMotors>)))
  "Returns md5sum for a message object of type '<CmdMotors>"
  "3ee8ef12710d8d370ae71ac748657306")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CmdMotors)))
  "Returns md5sum for a message object of type 'CmdMotors"
  "3ee8ef12710d8d370ae71ac748657306")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CmdMotors>)))
  "Returns full string definition for message of type '<CmdMotors>"
  (cl:format cl:nil "bool  startMotors~%uint8 motorLeft~%uint8 motorRight~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CmdMotors)))
  "Returns full string definition for message of type 'CmdMotors"
  (cl:format cl:nil "bool  startMotors~%uint8 motorLeft~%uint8 motorRight~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CmdMotors>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CmdMotors>))
  "Converts a ROS message object to a list"
  (cl:list 'CmdMotors
    (cl:cons ':startMotors (startMotors msg))
    (cl:cons ':motorLeft (motorLeft msg))
    (cl:cons ':motorRight (motorRight msg))
))
