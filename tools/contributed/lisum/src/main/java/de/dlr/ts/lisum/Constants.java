/*
 * Copyright (C) 2016
 * Deutsches Zentrum fuer Luft- und Raumfahrt e.V.
 * Institut fuer Verkehrssystemtechnik
 * 
 * German Aerospace Center
 * Institute of Transportation Systems
 * 
 */
package de.dlr.ts.lisum;

/**
 *
 * @author @author <a href="mailto:maximiliano.bottazzi@dlr.de">Maximiliano Bottazzi</a>
 */
public class Constants
{
    /**
     * 
     */
    public static final String DEFAULT_LOG_LEVEL = "INFO";
    
    /**
     * Properties keys
     */
    public static final String LISA_RESTFUL_SERVER_DIR = "lisa.RESTfulServerDir";
    public static final String LISA_RESTFUL_SERVER_ADDRESS = "lisa.serverAddress";
    public static final String LISA_RESTFUL_SERVER_PORT = "lisa.serverPort";
    //public static final String LISA_DATA_DIR = "lisa.dataDir";
    
    /**
     * 
     */
    public static final String GLOBAL_CONFIG_FILE_NAME = "config.xml";
    
    /**
     * Global config file keys
     */
    public static final String LISA_RESTFUL_SERVER_DIR_KEY = "lisa.RESTfulServer.directory";
    public static final String LISA_RESTFUL_SERVER_ADDRESSS_KEY = "lisa.RESTfulServer.address";
    public static final String LISA_RESTFUL_SERVER_PORT_KEY = "lisa.RESTfulServer.port";
    public static final String SUMO_EXEC_KEY = "sumo.exec";
    
    /**
     * LiSuM config file keys
     */
    public static final String LISA_FILES_DIRECTORY_KEY = "input.lisa";
    public static final String CONTROLUNITS_ITEM_KEY = "controlUnits.item";
    public static final String DETECTORS_ITEM_KEY = "detectors.item";
    
    /**
     * 
     */
    public static final int LISA_RESTFUL_SERVER_PORT_DEFAULT = 9091;
}