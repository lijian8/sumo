/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2012-2018 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    NBAlgorithms_Railway.h
/// @author  Jakob Erdmann
/// @author  Melanie Weber
/// @date    29. March 2018
/// @version $Id$
///
// Algorithms for railways
/****************************************************************************/
#ifndef NBAlgorithms_Railway_h
#define NBAlgorithms_Railway_h


// ===========================================================================
// included modules
// ===========================================================================
#include <config.h>

#include <vector>
#include "NBEdge.h"


// ===========================================================================
// class declarations
// ===========================================================================
class NBNetBuilder;
class OptionsCont;
class NBVehicle;


// ===========================================================================
// class definitions
// ===========================================================================
// ---------------------------------------------------------------------------
// NBAlgorithms_Railway
// ---------------------------------------------------------------------------
/* @class NBRampsComputer
 * @brief Computes highway on-/off-ramps (if wished)
 */
class NBRailwayTopologyAnalyzer {
public:
    /** @brief Computes highway on-/off-ramps (if wished)
     * @param[in, changed] nb The network builder which contains the current network representation
     * @param[in] oc The options container
     */
    static void analyzeTopology(NBNetBuilder& nb);
    static void repairTopology(NBNetBuilder& nb);
    static void makeAllBidi(NBNetBuilder& nb);

    /// routing edge
    class Track {
    public:
        Track(NBEdge *e, int i=-1, const std::string& _id="") : 
            edge(e),
            index(i < 0 ? edge->getNumericalID() : i),
            id(_id == "" ? edge->getID() : _id),
            minPermissions(edge->getPermissions())
            {}

        void addSuccessor(Track* track);
        const std::vector<Track*>& getSuccessors(SUMOVehicleClass svc) const;

        const std::string& getID() const { 
            return id;
        }
        int getNumericalID() const { 
            return index;
        }

        NBEdge* edge;

    private:
        const int index;
        const std::string id;
        std::vector<Track*> successors;
        SVCPermissions minPermissions;
        mutable std::map<SUMOVehicleClass, std::vector<Track*> > svcSuccessors;
    };
    static double getTravelTimeStatic(const Track* const track, const NBVehicle* const veh, double time);

private:
    static std::set<NBNode*> getRailNodes(NBNetBuilder& nb, bool verbose=false);
    static std::set<NBNode*> getBrokenRailNodes(NBNetBuilder& nb, bool verbose=false);

    /// @brief filter out rail edges among all edges of a the given node
    static void getRailEdges(const NBNode* node, EdgeVector& inEdges, EdgeVector& outEdges);

    static bool isStraight(const NBNode* node, const NBEdge* e1, const NBEdge* e2);
    static bool hasStraightPair(const NBNode* node, const EdgeVector& edges, const EdgeVector& edges2); 
    static bool allBroken(const NBNode* node, NBEdge* candOut, const EdgeVector& in, const EdgeVector& out);
    static bool allSharp(const NBNode* node, const EdgeVector& in, const EdgeVector& out, bool countBidiAsSharp=false);
    static bool allBidi(const EdgeVector& edges);
    static NBEdge* isBidiSwitch(const NBNode* n);

    /// @brief add bidi-edge for the given edge
    static NBEdge* addBidiEdge(NBNetBuilder& nb, NBEdge* edge, bool update=true);

    /// @brief add further bidi-edges near existing bidi-edges
    static int extendBidiEdges(NBNetBuilder& nb);
    static int extendBidiEdges(NBNetBuilder& nb, NBNode* node, NBEdge* bidiIn);

    /// @brief reverse edges sequences that are to broken nodes on both sides
    static void reverseEdges(NBNetBuilder& nb);

    /// @brief add bidi-edges to connect buffers stops in both directions
    static void addBidiEdgesForBufferStops(NBNetBuilder& nb);

    /// @brief add bidi-edges to connect switches that are approached in both directions
    static void addBidiEdgesBetweenSwitches(NBNetBuilder& nb);

    /// @brief add bidi-edges to connect successive public transport stops
    static void addBidiEdgesForStops(NBNetBuilder& nb);

    /// @brief whether the given tracks are connected (strongly or weakly depending on the router)
    static bool isConnnected(SUMOAbstractRouter<Track, NBVehicle>& router, 
        const Track* from, const Track* to, const NBVehicle* veh); 

    /// recompute turning directions for both nodes of the given edge
    static void updateTurns(NBEdge* edge);

};


#endif

/****************************************************************************/

