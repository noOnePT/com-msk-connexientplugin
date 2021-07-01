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
            case "loadMapNoId": {
                this.loadMap(null, callbackContext);
                return true;
            }
            case "isMapReady": {
                int mapId = args.getInt(0);
                this.isMapReady(mapId, callbackContext);
                return true;
            }
            case "isMapReadyNoId": {
                this.isMapReady(null, callbackContext);
                return true;
            }
            case "isMapDownloading": {
                int mapId = args.getInt(0);
                this.isMapDownloading(mapId, callbackContext);
                return true;
            }
            case "isMapDownloadingNoId": {
                this.isMapDownloading(null, callbackContext);
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

    private void loadMap(Integer mapId, CallbackContext callbackContext) {
        try {
            if (mapId == null){
                Medinav.loadMap();
            } else {
                Medinav.loadMap(mapId);
            }
            PluginResult result = new PluginResult(PluginResult.Status.OK, "Map loaded");
            callbackContext.sendPluginResult(result);
        } catch (Exception e){
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, e.getMessage());
            callbackContext.sendPluginResult(result);
        }
    }

    private void isMapReady(Integer mapId, CallbackContext callbackContext) {
        boolean isMapReady;
        if (mapId == null){
            isMapReady = Medinav.isMapReady();
        } else {
            isMapReady = Medinav.isMapReady(mapId);
        }
        PluginResult result = new PluginResult(PluginResult.Status.OK, isMapReady);
        callbackContext.sendPluginResult(result);
    }

    private void isMapDownloading(Integer mapId, CallbackContext callbackContext) {
        try {
            boolean isMapDownloading;
            if (mapId == null){
                isMapDownloading = Medinav.isMapDownloading();
            } else {
                isMapDownloading = Medinav.isMapDownloading(mapId);
            }
            PluginResult result = new PluginResult(PluginResult.Status.OK, isMapDownloading);
            callbackContext.sendPluginResult(result);
        } catch (Exception e){
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, e.getMessage());
            callbackContext.sendPluginResult(result);
        }
    }

    private void searchStaff(CallbackContext callbackContext) {
        try{
            Medinav.searchStaff(this.cordova.getActivity());
            PluginResult result = new PluginResult(PluginResult.Status.OK, "SearchStaff called");
            callbackContext.sendPluginResult(result);
        } catch (Exception e){
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, e.getMessage());
            callbackContext.sendPluginResult(result);
        }
    }

    private void showMap(CallbackContext callbackContext) {
        try{
            Medinav.showMap(this.cordova.getActivity());
            PluginResult result = new PluginResult(PluginResult.Status.OK, "Map will shown");
            callbackContext.sendPluginResult(result);
        } catch (Exception e){
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, e.getMessage());
            callbackContext.sendPluginResult(result);
        }
    }

    private void showDirectory(CallbackContext callbackContext) {
        try{
            Medinav.showDirectory(this.cordova.getActivity());
            PluginResult result = new PluginResult(PluginResult.Status.OK, "Directory will shown");
            callbackContext.sendPluginResult(result);
        } catch (Exception e){
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, e.getMessage());
            callbackContext.sendPluginResult(result);
        }
    }

    private void openLink(CallbackContext callbackContext, String deepLink) {
        try{
            Medinav.openLink(this.cordova.getActivity(), deepLink);
            PluginResult result = new PluginResult(PluginResult.Status.OK, "openLink was called");
            callbackContext.sendPluginResult(result);
        } catch (Exception e){
            PluginResult result = new PluginResult(PluginResult.Status.ERROR, e.getMessage());
            callbackContext.sendPluginResult(result);
        }
    }
}
