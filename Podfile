platform :ios, '11.0'
workspace 'ForeSeeSamples.xcworkspace'
use_frameworks!

FORESEE_VERSION = '6.0.0-alpha4'

def foresee_pods(include_feedback=false, include_cxMeasure=true)
    pod 'ForeSee/Core', FORESEE_VERSION
    pod 'ForeSee/ForeSeeCxMeasure', FORESEE_VERSION if include_cxMeasure
    pod 'ForeSee/ForeSeeFeedback', FORESEE_VERSION if include_feedback
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    foresee_pods
end

target "AdvancedSample" do
    project 'AdvancedSample/AdvancedSample.xcodeproj'
    foresee_pods true
end

target "BasicSample" do
    project 'BasicSample/BasicSample.xcodeproj'
    foresee_pods
end

target "AdobeExtensionSample" do
    project 'AdobeExtensionSample/AdobeExtensionSample.xcodeproj'
    pod 'ForeSeeAdobeExtension', '1.0.1-alpha4'
    pod 'ACPCore', '~> 2.0'
    pod 'ACPUserProfile', '~> 2.0'
end

target "SwiftSample" do
    project 'BasicSwiftSample/BasicSwiftSample.xcodeproj'
    foresee_pods
end

target "ContactInvitationSample" do
    project 'ContactInvitationSample/ContactInvitationSample.xcodeproj'
    foresee_pods
end

target "LocalNotificationSample" do
    project 'LocalNotificationSample/LocalNotificationSample.xcodeproj'
    foresee_pods
end

target "FeedbackSample" do
    project 'FeedbackSample/FeedbackSample.xcodeproj'
    foresee_pods true, false
end
