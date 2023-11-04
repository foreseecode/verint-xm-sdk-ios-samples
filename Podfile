source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '11.0'

workspace 'VerintSamples.xcworkspace'
use_frameworks!

POD_VERSION = '7.1.0'

def pods(include_digital=false, include_predictive=true, include_sm=false)
    pod 'Verint-XM/Core', POD_VERSION
    pod 'Verint-XM/Predictive', POD_VERSION if include_predictive
    pod 'Verint-XM/Digital', POD_VERSION if include_digital
    pod 'Verint-XM/SurveyManagement', POD_VERSION if include_sm
end

def dba_pods
    pod 'Verint-XM/DBA', POD_VERSION
end

target "AdvancedSample" do
    project 'AdvancedSample/AdvancedSample.xcodeproj'
    pods false, false, true
end

target "BasicSample" do
    project 'BasicSample/BasicSample.xcodeproj'
    pods false, false, true
end

target "BasicSwiftSample" do
    project 'BasicSwiftSample/BasicSwiftSample.xcodeproj'
    pods
end

target "ContactInvitationSample" do
    project 'ContactInvitationSample/ContactInvitationSample.xcodeproj'
    pods
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    pods
end

target "LocalNotificationSample" do
    project 'LocalNotificationSample/LocalNotificationSample.xcodeproj'
    pods
end

target "DBASample" do
    project 'DBASample/DBASample.xcodeproj'
    dba_pods
end
