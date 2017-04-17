
(cl:in-package :asdf)

(defsystem "manta-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "NavSatFix" :depends-on ("_package_NavSatFix"))
    (:file "_package_NavSatFix" :depends-on ("_package"))
    (:file "CmdMotors" :depends-on ("_package_CmdMotors"))
    (:file "_package_CmdMotors" :depends-on ("_package"))
    (:file "Echo" :depends-on ("_package_Echo"))
    (:file "_package_Echo" :depends-on ("_package"))
    (:file "Radio" :depends-on ("_package_Radio"))
    (:file "_package_Radio" :depends-on ("_package"))
    (:file "Imu" :depends-on ("_package_Imu"))
    (:file "_package_Imu" :depends-on ("_package"))
    (:file "Gps" :depends-on ("_package_Gps"))
    (:file "_package_Gps" :depends-on ("_package"))
  ))