/*! \file aerodynamics.h
 *    This file contains the definition of the aerodynamics namespace.
 *
 *    Path              : /Astrodynamics/ForceModels/
 *    Version           : 4
 *    Check status      : Checked
 *
 *    Author            : D. Dirkx
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : d.dirkx@tudelft.nl
 *
 *    Checker           : L. Abdulkadir
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : L.Abdulkadir@student.tudelft.nl
 *
 *    Checker           : K. Kumar
 *    Affiliation       : Delft University of Technology
 *    E-mail address    : K.Kumar@tudelft.nl
 *
 *    Date created      : 25 November, 2010
 *    Last modified     : 11 February, 2011
 *
 *    References
 *      Anderson Jr., J.D. , Fundamentals of Aerodynamics, 3rd edition,
 *          McGraw Hill, 2001.
 *      Gentry, A., Smyth, D., and Oliver, W. . The Mark IV Supersonic-
 *          Hypersonic Arbitrary Body Program, Volume II - Program Formulation,
 *          Douglas Aircraft Company, 1973.
 *      Anderson Jr. , J.D, Hypersonic and High-Temperature Gas Dynamics, 2nd
 *          edition, AIAA Education Series, 2006.
 *
 *    Notes
 *
 *    Copyright (c) 2010-2011 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      102511    D. Dirkx          First version of file.
 *      110501    D. Dirkx          Added more comments.
 *      110203    L. Abdulkadir     Code check.
 *      110211    K. Kumar          Corrected Doxygen errors; corrected layout errors; corrected
 *                                  function-naming.
 */

#ifndef AERODYNAMICS_H
#define AERODYNAMICS_H

// Include statements.
#include <cmath>

//! Tudat library namespace.
/*!
 * The Tudat library namespace.
 */
namespace tudat
{

//! Aerodynamics namespace.
/*!
 * The aerodynamics namespace.
 */
namespace aerodynamics
{

//! Maximum Prandtl-Meyer function value.
/*!
 * Maximum Prandtl-Meyer function value for ratio of specific heats = 1.4.
 */
static const double maximumPrandtlMeyerFunctionValue = M_PI / 2.0 * ( std::sqrt( 6.0 ) - 1.0 );

//! Constant for use in inverse Prandtl-Meyer function calculation.
/*!
 * Constant for use in inverse Prandtl-Meyer function calculation for ratio of
 *  specific heats = 1.4.
 */
static const double PrandtlMeyerParameter1 = 1.3604;

//! Constant for use in inverse Prandtl-Meyer function calculation.
/*!
 * Constant for use in inverse Prandtl-Meyer function calculation for ratio of
 * specific heats = 1.4.
 */
static const double PrandtlMeyerParameter2 = 0.0962;

//! Constant for use in inverse Prandtl-Meyer function calculation.
/*!
 * Constant for use in inverse Prandtl-Meyer function calculation for ratio of
 * specific heats = 1.4.
 */
static const double PrandtlMeyerParameter3 = -0.5127;

//! Constant for use in inverse Prandtl-Meyer function calculation.
/*!
 * Constant for use in inverse Prandtl-Meyer function calculation for ratio of
 * specific heats = 1.4.
 */
static const double PrandtlMeyerParameter4 = -0.6722;

//! Constant for use in inverse Prandtl-Meyer function calculation.
/*!
 * Constant for use in inverse Prandtl-Meyer function calculation for ratio of
 * specific heats = 1.4.
 */
static const double PrandtlMeyerParameter5 = -0.3278;

//! Compute local-to-static pressure ratio.
/*!
 * Computes the local to static pressure ratio, assuming a thermally and
 * calorically perfect gas.
 * \param machNumber Flow Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \return Local-to-static pressure ratio.
 */
double computeLocalToStaticPressureRatio( double machNumber,
                                          double ratioOfSpecificHeats );

//! Compute Prandtl-Meyer function.
/*!
 * Computes the value of the Prandtl-Meyer function at the given Mach number
 * and ratio of specific heat.
 * \param machNumber Flow Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \return Prandtl-Meyer function value.
 */
double computePrandtlMeyerFunction( double machNumber, double ratioOfSpecificHeats );

//! Compute stagnation pressure coefficient in supersonic flow.
/*!
 * Computes the stagnation pressure coefficient, assuming a thermally and
 * calorically perfect gas.
 * \param machNumber Flow Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \return Stagnation pressure coefficient.
 */
double computeStagnationPressure( double machNumber, double ratioOfSpecificHeats );

//! Compute pressure coefficient based on Newtonian theory.
/*!
 * Computes the pressure coefficient based on Newtonian theory.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \return Newtonian pressure coefficient.
 */
double computeNewtonianPressureCoefficient( double inclinationAngle );

//! Compute pressure coefficient based on modified Newtonian theory.
/*!
 * Computes the pressure coefficient based on modified Newtonian theory.
 * \param inclinationAngle Angle between the wall and the freestream
 *         velocity vector.
 * \param stagnationPressureCoefficient Stagnation pressure coefficient.
 * \return Newtonian pressure coefficient.
 */
double computeModifiedNewtonianPressureCoefficient(
        double inclinationAngle, double stagnationPressureCoefficient );

//! Compute pressure coefficient using empirical tangent wedge method.
/*!
 * Computes tangent wedge pressure coefficient based on empirical correlation
 * for ratio of specific heats = 1.4 ( terrestrial atmosphere).
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \return Empirical tangent wedge pressure coefficient.
 */
double computeEmpiricalTangentWedgePressureCoefficient(
        double inclinationAngle, double machNumber );

//! Compute pressure coefficient using empirical tangent cone method.
/*!
 * Computes tangent cone pressure coefficient based on empirical correlation
 * for ratio of specific heats = 1.4 ( terrestrial atmosphere).
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \return Empirical tangent wedge pressure coefficient.
 */
double computeEmpiricalTangentConePressureCoefficient(
        double inclinationAngle, double machNumber );

//! Compute pressure coefficient using modified Dahlem-Buck method.
/*!
 * Computes tangent cone pressure coefficient based on Dahlem-Buck empirical
 * method.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \return Dahlem-Buck pressure coefficient.
 */
double computeModifiedDahlemBuckPressureCoefficient(
        double inclinationAngle, double machNumber );

//! Compute pressure coefficient using the Hankey flat surface method.
/*!
 * Computes tangent cone pressure coefficient based on the Hankey flat surface
 * method.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \return Hankey Flat surface pressure coefficient.
 */
double computeHankeyFlatSurfacePressureCoefficient(
        double inclinationAngle, double machNumber );

//! Compute pressure coefficient using the Smyth delta wing method.
/*!
 * Computes tangent cone pressure coefficient based on the Smyth delta wing
 * surface method.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \return Smyth delta wing pressure coefficient.
 */
double computeSmythDeltaWingPressureCoefficient(
        double inclinationAngle, double machNumber );

//! Compute pressure coefficient using the van Dyke unified method.
/*!
 * Computes tangent cone pressure coefficient based on the van Dyke unified
 * method.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \param type ( expansion ( 1 ) or compression( -1 ) ).
 * \return Hankey Flat surface pressure coefficient.
 */
double computeVanDykeUnifiedPressureCoefficient(
        double inclinationAngle, double machNumber,
        double ratioOfSpecificHeats, int type );

//! Compute pressure coefficient using Prandtl-Meyer expansion.
/*!
 * Computes pressure coefficient using Prandtl-Meyer expansion from
 * freestream. Currently only terrestrial atmosphere
 * ( ratio of specific heat = 1.4 ) is supported due to the use of an empirical
 * fit for the inverse Prandtl-Meyer function determination.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \param freestreamPrandtlMeyerFunction Freestream Prandtl-Meyer function.
 * \return Prandtl-Meyer pressure coefficient.
 */
double computePrandtlMeyerFreestreamPressureCoefficient(
        double inclinationAngle,  double machNumber,
        double ratioOfSpecificHeats, double freestreamPrandtlMeyerFunction );

//! Compute pressure coefficient at vacuum.
/*!
 * Computes the pressure coefficient at vacuum assuming a thermally and
 * calorically perfect gas.
 * \param machNumber Flow Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \return Vacuum pressure coefficient.
 */
double computeVacuumPressureCoefficient(
        double machNumber, double ratioOfSpecificHeats );

//! Compute high Mach base pressure coefficient.
/*!
 * This function calculates the high Mach base pressure coefficient
 * approximation.
 * \param machNumber Flow Mach number.
 * \return Vacuum pressure coefficient.
 */
double computeHighMachBasePressure( double machNumber );

//! Compute pressure coefficient using the ACM empirical method.
/*! Computes tangent cone pressure coefficient based on the ACM empirical
 * method.
 * \param inclinationAngle Angle between wall and freestream velocity vector.
 * \param machNumber Flow Mach number.
 * \return ACM empirical surface pressure coefficient.
 */
double computeAcmEmpiricalPressureCoefficient(
        double inclinationAngle, double machNumber );

//! Compute Mach number from Prandtl-Meyer function.
/*!
 * Computes the inverse of the Prandtl-Meyer function. Currently the function
 * is limited to use with ratio of specific heats of 1.4 as it uses an
 * empirical correlation.
 * \param prandtlMeyerFunctionValue Prandyl-Meyer function value.
 * \return Mach number.
 */
double computeInversePrandtlMeyerFunction( double prandtlMeyerFunctionValue );

//! Compute ratio of post- to pre-shock pressure.
/*!
 * Computes ratio of post- to pre-shock pressure, assuming thermally and calorically perfect gas.
 * \param normalMachNumber Mach number of flow velocity normal to shock.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *          specific heat at constant volume.
 */
double computeShockPressureRatio( double normalMachNumber,
                                  double ratioOfSpecificHeats );

//! Compute ratio of post- to pre-shock density.
/*!
 * Compute ratio of post- to pre-shock density, assuming thermally and calorically perfect gas.
 * \param normalMachNumber Mach number of flow velocity normal to shock.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 */
double computeShockDensityRatio( double normalMachNumber,
                                 double ratioOfSpecificHeats );

//! Compute ratio of post- to pre-shock temperature.
/*!
 * Computes ratio of post- to pre-shock temperature, assuming thermally and calorically perfect
 * gas.
 * \param normalMachNumber Mach number of flow velocity normal to shock.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 */
double computeShockTemperatureRatio( double normalMachNumber,
                                     double ratioOfSpecificHeats );

//! Compute jump in entropy across a shock wave.
/*!
 * Compute jump in entropy across a shock wave, assuming thermally and calorically perfect gas.
 * \param normalMachNumber Mach number of flow velocity normal to shock.
 * \param ratioOfSpecificHeats ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \param specificGasConstant gas constant per unit mass for flow composition.
 */
double computeShockEntropyJump( double normalMachNumber, double ratioOfSpecificHeats,
                                double specificGasConstant );

//! Compute post- to pre-shock total pressure ratio.
/*!
 * Compute post- to pre-shock total pressure ratio from the entropy jump across
 * a shock wave. Assumption of thermally and calorically perfect gas is made.
 * \param normalMachNumber Mach number of flow velocity normal to shock.
 * \param ratioOfSpecificHeats ratio of specific heat at constant pressure to
 *         specific heat at constant volume.
 * \param specificGasConstant gas constant per unit mass for flow composition.
 */
double computeShockTotalPressureRatio( double normalMachNumber,
                                       double ratioOfSpecificHeats,
                                       double specificGasConstant );

//! Compute shock deflection angle.
/*!
 * Computes the flow deflection angle across a shock wave.
 * \param shockAngle Angle of shock wave w.r.t. freestream flow.
 * \param machNumber Freestream Mach number.
 * \param ratioOfSpecificHeats Ratio of specific heat at constant pressure to
 *          specific heat at constant volume.
 */
double computeShockDeflectionAngle( double shockAngle, double machNumber,
                                    double ratioOfSpecificHeats );

}

}

#endif // AERODYNAMICS_H

// End of file.