# Trust-Tools
A collection of resources for creating trusted computational results

## Overview
Published computational results must be trustworthy in order to advance science and engineering.  The need has grown over time, as computation becomes an ever-increasing element of advances in science and technology.  Fortunately, tools, processes and practices have also emerged to assist computational scientist and engineers in establishing the trustworthiness of their results.

This repository contains information on approaches to improving trustworthiness, and pointers to some of the tools and references that can be helpful.

## Fundamental concepts related to trustworthy results
Trusted computational results require focus on both internal and external concerns.  While external, independent confirmation of a particular computational result is the most effective way to increase trust, knowing the details of how a result was computed is also important.  Transparency into how a result was computed allows us to better understand the parameter space that produced the result.  Understanding the computational environment used to produce the result, and having access to that environment in the future, better assures that a result is not just a single outcome that might be misleading, but is part of a family of results that we can build upon going forward.

For example, suppose I know a reliable make of automobile that has been used to travel across 500 miles of desert on a regular basis. I will likely have confidence that I can safely travel 500 miles across the desert with a vehicle of this kind.  I might also assume that I can trust it to travel 600 miles.  However, if the vehicle has a fuel efficiency of 26 miles per gallon and a 20 gallon gas tank, a detail of how it can be trustworthy for 500 miles, my 600-mile trip would not go well.

One framework for reasoning about trustworthiness is to consider three terms: transparency,reproducibility and replicability.

| Term            | Definition       |
|-----------------|------------------|
| Transparency    | All data and software used to produce a result are available with sufficient documentation. |
| Reproducibility | Results can be computed by someone else using the author's environment. |
| Replicability   | Consistent results can be obtained using another environment. |

