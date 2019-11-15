#  HOWTO Trigger a Satisfaction Survey Invitation

This example demonstrtates a ForeSee measure survey triggered by "page views" and a custom "significant event" count, which can be incremented using a button in the app. The user will
become eligibile to receive and invitation once the configured thresholds are met. 

How to trigger the survey:

1. Meet the page views count (2). The AppDelegate counts as one view. This ViewController counts as another. Tap "Show Feedback" to launch a Feedback survey, which will also increase the page view count.

2. Meet the custom event  threshold (4). Tap the "Increment Event" button to increase the event count.

3. Tap "Check Invite Eligibility" at any time to check eligibility. This action writes the current criteria state to the debug console.

4. Tap "Reset State" to reset the counters. The state is also reset each time this ViewController is loaded. (This is done to simplify this example; in a production app you would track state across user launches of your application.)
