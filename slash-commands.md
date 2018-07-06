# Slash Commands

## Setting Up Endpoint (AWS)
First, we need to have an endpoint for the slash command. Create a new function on AWS Lambda. For a simple "Hello World" example:

index.js
```
exports.handler = function (event, context, callback) {
    callback(null, "Hello World!");
}
```  

Next, go to *API Gateway* in the left bar. Choose "Create a new API", enter in basic information, then submit. Once submitted, go to the page for the API by clicking on its link. 

Then, click on the *Integration Request* box on the diagram. Scroll all the way to the bottom for *Body Mapping Templates*. Because Slack sends content as  "applicatoin/x-www-form-urlencoded", go ahead and add a mapping for "application/x-www-form-urlencoded". Generate a simple template by using passthrough. Submit and deploy the API.

An endpoint is generated, and you should now be able to test it. We can also retrieve the information sent by Slack. 

index.js
```
var querystring = require('querystring');

exports.handler = function (event, context, callback) {
    const body = querystring.parse(event['body-json']);
    callback(null, body);
}
```  

## Adding a webhook
Basic Information -> Add features and functionality -> Slash Commands

Use the endpoint from previous step.



