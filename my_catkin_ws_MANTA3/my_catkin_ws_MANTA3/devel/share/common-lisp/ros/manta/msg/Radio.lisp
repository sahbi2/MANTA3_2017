; Auto-generated. Do not edit!


(cl:in-package manta-msg)


;//! \htmlinclude Radio.msg.html

(cl:defclass <Radio> (roslisp-msg-protocol:ros-message)
  ((message
    :reader message
    :initarg :message
    :type cl:fixnum
    :initform 0)
   (valeur1
    :reader valeur1
    :initarg :valeur1
    :type cl:fixnum
    :initform 0)
   (valeur2
    :reader valeur2
    :initarg :valeur2
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Radio (<Radio>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Radio>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Radio)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name manta-msg:<Radio> is deprecated: use manta-msg:Radio instead.")))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <Radio>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:message-val is deprecated.  Use manta-msg:message instead.")
  (message m))

(cl:ensure-generic-function 'valeur1-val :lambda-list '(m))
(cl:defmethod valeur1-val ((m <Radio>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:valeur1-val is deprecated.  Use manta-msg:valeur1 instead.")
  (valeur1 m))

(cl:ensure-generic-function 'valeur2-val :lambda-list '(m))
(cl:defmethod valeur2-val ((m <Radio>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader manta-msg:valeur2-val is deprecated.  Use manta-msg:valeur2 instead.")
  (valeur2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Radio>) ostream)
  "Serializes a message object of type '<Radio>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'message)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'valeur1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'valeur2)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Radio>) istream)
  "Deserializes a message object of type '<Radio>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'message)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'valeur1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'valeur2)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Radio>)))
  "Returns string type for a message object of type '<Radio>"
  "manta/Radio")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Radio)))
  "Returns string type for a message object of type 'Radio"
  "manta/Radio")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Radio>)))
  "Returns md5sum for a message object of type '<Radio>"
  "2429ef2946c76f9c323459f6315b9f76")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Radio)))
  "Returns md5sum for a message object of type 'Radio"
  "2429ef2946c76f9c323459f6315b9f76")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Radio>)))
  "Returns full string definition for message of type '<Radio>"
  (cl:format cl:nil "uint8 message~%uint8 valeur1~%uint8 valeur2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Radio)))
  "Returns full string definition for message of type 'Radio"
  (cl:format cl:nil "uint8 message~%uint8 valeur1~%uint8 valeur2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Radio>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Radio>))
  "Converts a ROS message object to a list"
  (cl:list 'Radio
    (cl:cons ':message (message msg))
    (cl:cons ':valeur1 (valeur1 msg))
    (cl:cons ':valeur2 (valeur2 msg))
))
