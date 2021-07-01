var exec = require('cordova/exec');

/*

SDK ENVS 
DEV,
DEV2,
NEWDEV,
STAGING,
PROD;
*/
module.exports = {
    setEnvironment: function (arg0, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'setEnvironment', [arg0]);
    },
    initAsync: function (apiKey, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'initAsync', [apiKey]);
    },
    loadMap: function (mapId, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'loadMap', [mapId]);
    },
    isMapDownloading: function (mapId, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'isMapDownloading', [mapId]);
    },
    isMapReady: function (mapId, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'isMapReady', [mapId]);
    },
    searchStaff: function (mapId, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'searchStaff');
    },
    showMap: function (success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'showMap');
    },
    showDirectory: function (success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'showDirectory');
    },
    openLink: function (deepLink, success, error) {
        exec(success, error, 'MSKConnexientPlugin', 'openLink', [deepLink]);
    }
}