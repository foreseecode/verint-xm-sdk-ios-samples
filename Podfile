source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '9.0'
workspace 'ForeSeeSamples.xcworkspace'
use_frameworks!

POD_VERSION = '7.0.1'

def pods(include_digital=false, include_predictive=true)
    pod 'Verint-XM/Core', POD_VERSION
    pod 'Verint-XM/Predictive', POD_VERSION if include_predictive
    pod 'Verint-XM/Digital', POD_VERSION if include_digital
end

def dba_pods
    pod 'Verint-XM/DBA', POD_VERSION
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    pods
end

target "AdvancedSample" do
    project 'AdvancedSample/AdvancedSample.xcodeproj'
    pods true
end

target "BasicSample" do
    project 'BasicSample/BasicSample.xcodeproj'
    pods
end

target "BasicSwiftSample" do
    project 'BasicSwiftSample/BasicSwiftSample.xcodeproj'
    pods
end

target "ContactInvitationSample" do
    project 'ContactInvitationSample/ContactInvitationSample.xcodeproj'
    pods
end

target "LocalNotificationSample" do
    project 'LocalNotificationSample/LocalNotificationSample.xcodeproj'
    pods
end

target "FeedbackSample" do
    project 'FeedbackSample/FeedbackSample.xcodeproj'
    pods true, false
end

target "DBASample" do
    project 'DBASample/DBASample.xcodeproj'
    dba_pods
end
