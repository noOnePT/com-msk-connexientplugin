"use strict";

var path = require("path");
var AdmZip = require("adm-zip");

var utils = require("./utilities");

var constants = {
  connexientAssets: "connexient-assets-"
};

module.exports = function(context) {
  var cordovaAbove8 = utils.isCordovaAbove(context, 8);
  var defer;
  if (cordovaAbove8) {
    defer = require("q").defer();
  } else {
    defer = context.requireCordovaModule("q").defer();
  }
  
  var platform = context.opts.plugin.platform;
  var platformConfig = utils.getPlatformConfigs(platform);
  if (!platformConfig) {
    utils.handleError("Invalid platform", defer);
  }

  var assetsFolder = utils.getResourcesFolderPath(context, platform, platformConfig);
  var sourceFolderPath = utils.getSourceFolderPath(context, assetsFolder);
  console.log("sourceFolderPath", sourceFolderPath);
  var connexientAssetsZipFile = utils.getZipFile(sourceFolderPath, constants.connexientAssets + platform);

  console.log("connexientAssetsZipFile", connexientAssetsZipFile);

  if (!connexientAssetsZipFile) {
    utils.handleError("No zip file found containing connexient assets", defer);
  }

  var zip = new AdmZip(connexientAssetsZipFile);

  var targetPath = path.join(context.opts.plugin.dir, "assets");
  zip.extractAllTo(targetPath, true);
  defer.resolve();
      
  return defer.promise;
}