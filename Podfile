platform :ios, '9.0'
workspace 'ForeSeeSamples.xcworkspace'
use_frameworks!

FORESEE_VERSION = '6.0.4-alpha0'

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

target "BasicSwiftSample" do
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

post_install do |installer|
    installer.pods_project.targets.each do |target|
        target.build_configurations.each do |config|
            config.build_settings['BUILD_LIBRARY_FOR_DISTRIBUTION'] = 'YES'
        end
    end
end
