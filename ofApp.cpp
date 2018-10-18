#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);

	int span = 30;
	for (int x = 0; x <= ofGetWidth(); x += span) {

		for (int y = 0; y <= ofGetHeight(); y += span) {

			this->locations.push_back(ofPoint(x, y));
		}
	}

	for (int i = 0; i < this->locations.size(); i++) {

		vector<int> next_index = vector<int>();
		for (int j = 0; j < this->locations.size(); j++) {

			if (i == j ){ continue; }

			float distance = this->locations[i].distance(this->locations[j]);
			if (distance <= span) {

				next_index.push_back(j);
			}
		}

		this->next_indexes.push_back(next_index);
	}

	for (int i = 0; i < 400; i++) { this->particles.push_back(Particle(this->locations, this->next_indexes)); }
}
//--------------------------------------------------------------
void ofApp::update() {

	for (Particle& particle : this->particles) { particle.Upate(); }
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (Particle& particle : this->particles) { particle.Draw(this->particles); }
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}