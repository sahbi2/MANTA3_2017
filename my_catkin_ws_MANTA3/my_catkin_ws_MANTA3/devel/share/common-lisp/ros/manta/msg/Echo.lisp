; Auto-generated. Do not edit!


(cl:in-package manta-msg)


;//! \htmlinclude Echo.msg.html

(cl:defclass <Echo> (roslisp-msg-protocol:ros-message)
  ((profondeur
    :reader profondeur
    :initarg :profondeur
    :type cl:float
    :initform 0.0))
)

(cl:defclass Echo (<Echo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Echo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Echo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name manta-msg:<Echo> is deprecated: use manta-msg:Echo instead.")))

(cl:ensure-generic-function 'profondeur-val :lambda-list '(m))
(cl:defmethod profondeur-val ((m <Echo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:profondeur-val is deprecated.  Use manta-msg:profondeur instead.")
  (profondeur m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Echo>) ostream)
  "Serializes a message object of type '<Echo>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'profondeur))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Echo>) istream)
  "Deserializes a message object of type '<Echo>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'profondeur) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Echo>)))
  "Returns string type for a message object of type '<Echo>"
  "manta/Echo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Echo)))
  "Returns string type for a message object of type 'Echo"
  "manta/Echo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Echo>)))
  "Returns md5sum for a message object of type '<Echo>"
  "b2e0694a5f1544fb7c77b695e4945a13")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Echo)))
  "Returns md5sum for a message object of type 'Echo"
  "b2e0694a5f1544fb7c77b695e4945a13")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Echo>)))
  "Returns full string definition for message of type '<Echo>"
  (cl:format cl:nil "float64  profondeur~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Echo)))
  "Returns full string definition for message of type 'Echo"
  (cl:format cl:nil "float64  profondeur~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Echo>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Echo>))
  "Converts a ROS message object to a list"
  (cl:list 'Echo
    (cl:cons ':profondeur (profondeur msg))
))
