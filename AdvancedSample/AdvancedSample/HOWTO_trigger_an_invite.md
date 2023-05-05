#  HOWTO Trigger a Satisfaction Survey Invitation

This example demonstrates a Verint Predictive survey triggered by "page views" and a custom "significant event" count, which can be incremented using a button in the app. The user will
become eligibile to receive and invitation once the configured thresholds are met. 

How to trigger the survey:

1. Meet the page views count (2). The AppDelegate counts as one view. This main ViewController counts as another. Tap "Show Survey" to launch a Digital survey, which will also increase the page view count.

2. Meet the custom event threshold (4). Tap the "Increment Event" button to increase the event count.

3. For default invites, Tap "Check Invite Eligibility" at any time to check eligibility. This action writes the current criteria state to the debug console. Look for the current counts there.

4. For custom invites, Tap "Custom Invite" to enter a custom invite sample screen. If any criteria is met, an in-line invite will be displayed.

5. Tap "Reset State" to reset the counters. The state is also reset each time the main ViewController is loaded. (This is done to simplify this example; in a production app you would track state across user launches of your application.)
