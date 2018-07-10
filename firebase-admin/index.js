var admin = require('firebase-admin');
var serviceAccount = require("./service-account.json");

admin.initializeApp({
    credential: admin.credential.cert(serviceAccount),
    databaseURL: "https://metal-air-192104.firebaseio.com"
});

 // test auth
// admin.auth().createCustomToken('123', {mapId:"map123", markerId:"marker1"} )
// .then(function(token) {
//     console.log('token', token);
// })
// .catch(function(error) {
//     console.log("Error creating custom token:", error);
// });

admin.auth().createCustomToken('123', {mapId:"map123", markerId:"marker2"} )
.then(function(token) {
    console.log('token', token);
})
.catch(function(error) {
    console.log("Error creating custom token:", error);
});