package com.msk.connexientplugin;

import android.app.Application;
import android.util.Log;

import com.connexient.medinav3.Medinav;
import com.connexient.sdk.ConnexientSdk;
import com.connexient.sdk.core.enums.Environment;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class MSKConnexientPlugin extends CordovaPlugin {

    static String TAG = "MSKConnexientPlugin";
    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {

        switch (action){
            case "setEnvironment": {
                String envStr = args.getString(0);
                this.setEnvironment(envStr, callbackContext);
                return true;
            }
            case "initAsync": {
                String apiKey = args.getString(0);
                this.initAsync(apiKey, callbackContext);
                return true;
            }
            case "loadMap": {
                int mapId = args.getInt(0);
                this.loadMap(mapId, callbackContext);
                return true;
            }
            case "isMapReady": {
                int mapId = args.getInt(0);
                this.isMapReady(mapId, callbackContext);
                return true;
            }
            case "isMapDownloading": {
                int mapId = args.getInt(0);
                this.isMapDownloading(mapId, callbackContext);
                return true;
            }
            case "searchStaff": {
                this.searchStaff(callbackContext);
                return true;
            }
            case "showMap": {
                this.showMap(callbackContext);
                return true;
            }
            case "showDirectory": {
                this.showDirectory(callbackContext);
                return true;
            }
            case "openLink": {
                String deepLink = args.getString(0);
                this.openLink(callbackContext, deepLink);
                return true;
            }
        }

        return false;
    }

    private void setEnvironment(String envStr, CallbackContext callbackContext) {
        if (envStr != null && envStr.length() > 0) {
            ConnexientSdk.getInstance().setEnvironment(Environment.valueOf(envStr));
            PluginResult result = new PluginResult(PluginResult.Status.OK);
            callbackContext.sendPluginResult(result);
        } else {
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, "Expected one non-empty string argument.");
            callbackContext.sendPluginResult(result);
        }
    }

    private void initAsync(String apiKey, CallbackContext callbackContext) {
        Application currApp = this.cordova.getActivity().getApplication();
        ConnexientSdk.getInstance().initAsync(this.cordova.getContext(), apiKey,
            new ConnexientSdk.SdkInitCallback() {
                @Override
                public void onSuccess() {
                    String msg = "SDK initialized successfully.";
                    Log.d(TAG, msg);
                    Medinav.init(currApp);
                    Medinav.loadMap();
                    PluginResult result = new PluginResult(PluginResult.Status.OK);
                    result.setKeepCallback(true);
                    callbackContext.sendPluginResult(result);
                }
                @Override
                public void onFail(int code) {
                    String msg = "SDK initialization failed with error code: " + code;
                    Log.e(TAG, msg);
                    PluginResult result = new PluginResult(PluginResult.Status.ERROR, msg);
                    result.setKeepCallback(true);
                    callbackContext.sendPluginResult(result);
                }
                @Override
                public void onException(Throwable throwable) {
                    String msg = "Exception while initializing SDK: " + throwable.getMessage();
                    Log.e(TAG, msg);
                    PluginResult result = new PluginResult(PluginResult.Status.ERROR, msg);
                    result.setKeepCallback(true);
                    callbackContext.sendPluginResult(result);
                }
            });
    }

    private void loadMap(int mapId, CallbackContext callbackContext) {
        Medinav.loadMap(mapId);
        PluginResult result = new PluginResult(PluginResult.Status.OK, "Map loaded");
        callbackContext.sendPluginResult(result);
    }

    private void isMapReady(int mapId, CallbackContext callbackContext) {
        boolean isMapReady = Medinav.isMapReady(mapId);
        PluginResult result = new PluginResult(PluginResult.Status.OK, isMapReady);
        callbackContext.sendPluginResult(result);
    }

    private void isMapDownloading(int mapId, CallbackContext callbackContext) {
        boolean isMapDownloading = Medinav.isMapDownloading(mapId);
        PluginResult result = new PluginResult(PluginResult.Status.OK, isMapDownloading);
        callbackContext.sendPluginResult(result);
    }

    private void searchStaff(CallbackContext callbackContext) {
        Medinav.searchStaff(this.cordova.getActivity());
        PluginResult result = new PluginResult(PluginResult.Status.OK, "SearchStaff called");
        callbackContext.sendPluginResult(result);
    }

    private void showMap(CallbackContext callbackContext) {
        Medinav.showMap(this.cordova.getActivity());
        PluginResult result = new PluginResult(PluginResult.Status.OK, "Map will shown");
        callbackContext.sendPluginResult(result);
    }

    private void showDirectory(CallbackContext callbackContext) {
        Medinav.showDirectory(this.cordova.getActivity());
        PluginResult result = new PluginResult(PluginResult.Status.OK, "Directory will shown");
        callbackContext.sendPluginResult(result);
    }

    private void openLink(CallbackContext callbackContext, String deepLink) {
        Medinav.openLink(this.cordova.getActivity(), deepLink);
        PluginResult result = new PluginResult(PluginResult.Status.OK, "openLink was called");
        callbackContext.sendPluginResult(result);
    }
}
