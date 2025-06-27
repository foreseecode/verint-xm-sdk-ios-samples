source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '12.0'

workspace 'VerintSamples.xcworkspace'
use_frameworks!

POD_VERSION = '7.5.2'

def pods
    pod 'Verint-XM/Core', POD_VERSION
    pod 'Verint-XM/SurveyManagement', POD_VERSION
end

def dba_pods
    pod 'Verint-XM/DBA', POD_VERSION
end

target "AdvancedSample" do
    project 'AdvancedSample/AdvancedSample.xcodeproj'
    pods
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

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    pods
end

target "DBASample" do
    project 'DBASample/DBASample.xcodeproj'
    dba_pods
end

target "LocalNotificationSample" do
    project 'LocalNotificationSample/LocalNotificationSample.xcodeproj'
    pods
end
