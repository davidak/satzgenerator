/* satzgenerator.c generated by valac 0.26.1, the Vala compiler
 * generated from satzgenerator.gs, do not modify */

/*
Copyright (C) 2015 davidak

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see {http://www.gnu.org/licenses/}.
*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>
#include <locale.h>

#define _g_free0(var) (var = (g_free (var), NULL))



gchar** lese (const gchar* datei, int* result_length1);
gchar* person (gchar** vornamen_m, int vornamen_m_length1);
gchar* satz (const gchar* p, gchar** verben, int verben_length1, gchar** adjektive, int adjektive_length1, gchar** orte, int orte_length1);
void _vala_main (gchar** args, int args_length1);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);

const gchar* beziehung_m[10] = {"Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner"};
const gchar* beziehung_w[10] = {"Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin"};
const gchar* possessivpronomen_m[4] = {"Mein", "Dein", "Sein", "Ihr"};
const gchar* spezial[10] = {"Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch"};

gchar** lese (const gchar* datei, int* result_length1) {
	gchar** result = NULL;
	gchar* s = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar** _tmp2_ = NULL;
	gchar** _tmp3_ = NULL;
	gchar** _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (datei != NULL, NULL);
	_tmp0_ = datei;
	g_file_get_contents (_tmp0_, &_tmp1_, NULL, &_inner_error_);
	_g_free0 (s);
	s = _tmp1_;
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		_g_free0 (s);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_tmp3_ = _tmp2_ = g_strsplit (s, "\n", 0);
	_tmp4_ = _tmp3_;
	_tmp4__length1 = _vala_array_length (_tmp2_);
	if (result_length1) {
		*result_length1 = _tmp4__length1;
	}
	result = _tmp4_;
	_g_free0 (s);
	return result;
}


gchar* person (gchar** vornamen_m, int vornamen_m_length1) {
	gchar* result = NULL;
	gint z = 0;
	gint32 _tmp0_ = 0;
	gchar* s = NULL;
	gint _tmp1_ = 0;
	_tmp0_ = g_random_int_range ((gint32) 1, (gint32) 6);
	z = (gint) _tmp0_;
	_tmp1_ = z;
	switch (_tmp1_) {
		case 1:
		{
			{
				gchar** _tmp2_ = NULL;
				gint _tmp2__length1 = 0;
				gchar** _tmp3_ = NULL;
				gint _tmp3__length1 = 0;
				gint32 _tmp4_ = 0;
				const gchar* _tmp5_ = NULL;
				gchar* _tmp6_ = NULL;
				gchar* _tmp7_ = NULL;
				gint32 _tmp8_ = 0;
				const gchar* _tmp9_ = NULL;
				gchar* _tmp10_ = NULL;
				_tmp2_ = vornamen_m;
				_tmp2__length1 = vornamen_m_length1;
				_tmp3_ = vornamen_m;
				_tmp3__length1 = vornamen_m_length1;
				_tmp4_ = g_random_int_range ((gint32) 0, (gint32) _tmp3__length1);
				_tmp5_ = _tmp2_[_tmp4_];
				_tmp6_ = g_strconcat (_tmp5_, "s ", NULL);
				_tmp7_ = _tmp6_;
				_tmp8_ = g_random_int_range ((gint32) 0, (gint32) G_N_ELEMENTS (beziehung_m));
				_tmp9_ = beziehung_m[_tmp8_];
				_tmp10_ = g_strconcat (_tmp7_, _tmp9_, NULL);
				_g_free0 (s);
				s = _tmp10_;
				_g_free0 (_tmp7_);
			}
			break;
		}
		case 2:
		{
			{
				gint32 _tmp11_ = 0;
				const gchar* _tmp12_ = NULL;
				gchar* _tmp13_ = NULL;
				gchar* _tmp14_ = NULL;
				gint32 _tmp15_ = 0;
				const gchar* _tmp16_ = NULL;
				gchar* _tmp17_ = NULL;
				_tmp11_ = g_random_int_range ((gint32) 0, (gint32) G_N_ELEMENTS (possessivpronomen_m));
				_tmp12_ = possessivpronomen_m[_tmp11_];
				_tmp13_ = g_strconcat (_tmp12_, " ", NULL);
				_tmp14_ = _tmp13_;
				_tmp15_ = g_random_int_range ((gint32) 0, (gint32) G_N_ELEMENTS (beziehung_m));
				_tmp16_ = beziehung_m[_tmp15_];
				_tmp17_ = g_strconcat (_tmp14_, _tmp16_, NULL);
				_g_free0 (s);
				s = _tmp17_;
				_g_free0 (_tmp14_);
			}
			break;
		}
		case 3:
		{
			{
				gint32 _tmp18_ = 0;
				const gchar* _tmp19_ = NULL;
				gchar* _tmp20_ = NULL;
				gchar* _tmp21_ = NULL;
				gint32 _tmp22_ = 0;
				const gchar* _tmp23_ = NULL;
				gchar* _tmp24_ = NULL;
				_tmp18_ = g_random_int_range ((gint32) 0, (gint32) G_N_ELEMENTS (possessivpronomen_m));
				_tmp19_ = possessivpronomen_m[_tmp18_];
				_tmp20_ = g_strconcat (_tmp19_, "e ", NULL);
				_tmp21_ = _tmp20_;
				_tmp22_ = g_random_int_range ((gint32) 0, (gint32) G_N_ELEMENTS (beziehung_w));
				_tmp23_ = beziehung_w[_tmp22_];
				_tmp24_ = g_strconcat (_tmp21_, _tmp23_, NULL);
				_g_free0 (s);
				s = _tmp24_;
				_g_free0 (_tmp21_);
			}
			break;
		}
		case 4:
		{
			{
				gint32 _tmp25_ = 0;
				const gchar* _tmp26_ = NULL;
				gchar* _tmp27_ = NULL;
				_tmp25_ = g_random_int_range ((gint32) 0, (gint32) G_N_ELEMENTS (spezial));
				_tmp26_ = spezial[_tmp25_];
				_tmp27_ = g_strdup (_tmp26_);
				_g_free0 (s);
				s = _tmp27_;
			}
			break;
		}
		default:
		{
			{
				gchar** _tmp28_ = NULL;
				gint _tmp28__length1 = 0;
				gchar** _tmp29_ = NULL;
				gint _tmp29__length1 = 0;
				gint32 _tmp30_ = 0;
				const gchar* _tmp31_ = NULL;
				gchar* _tmp32_ = NULL;
				_tmp28_ = vornamen_m;
				_tmp28__length1 = vornamen_m_length1;
				_tmp29_ = vornamen_m;
				_tmp29__length1 = vornamen_m_length1;
				_tmp30_ = g_random_int_range ((gint32) 0, (gint32) _tmp29__length1);
				_tmp31_ = _tmp28_[_tmp30_];
				_tmp32_ = g_strdup (_tmp31_);
				_g_free0 (s);
				s = _tmp32_;
			}
			break;
		}
	}
	result = s;
	return result;
}


gchar* satz (const gchar* p, gchar** verben, int verben_length1, gchar** adjektive, int adjektive_length1, gchar** orte, int orte_length1) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar** _tmp3_ = NULL;
	gint _tmp3__length1 = 0;
	gchar** _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	gint32 _tmp5_ = 0;
	const gchar* _tmp6_ = NULL;
	gchar* _tmp7_ = NULL;
	gchar* _tmp8_ = NULL;
	gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	gchar** _tmp11_ = NULL;
	gint _tmp11__length1 = 0;
	gchar** _tmp12_ = NULL;
	gint _tmp12__length1 = 0;
	gint32 _tmp13_ = 0;
	const gchar* _tmp14_ = NULL;
	gchar* _tmp15_ = NULL;
	gchar* _tmp16_ = NULL;
	gchar* _tmp17_ = NULL;
	gchar* _tmp18_ = NULL;
	gchar** _tmp19_ = NULL;
	gint _tmp19__length1 = 0;
	gchar** _tmp20_ = NULL;
	gint _tmp20__length1 = 0;
	gint32 _tmp21_ = 0;
	const gchar* _tmp22_ = NULL;
	gchar* _tmp23_ = NULL;
	gchar* _tmp24_ = NULL;
	gchar* _tmp25_ = NULL;
	gchar* _tmp26_ = NULL;
	g_return_val_if_fail (p != NULL, NULL);
	_tmp0_ = p;
	_tmp1_ = g_strconcat (_tmp0_, " ", NULL);
	_tmp2_ = _tmp1_;
	_tmp3_ = verben;
	_tmp3__length1 = verben_length1;
	_tmp4_ = verben;
	_tmp4__length1 = verben_length1;
	_tmp5_ = g_random_int_range ((gint32) 0, (gint32) _tmp4__length1);
	_tmp6_ = _tmp3_[_tmp5_];
	_tmp7_ = g_strconcat (_tmp2_, _tmp6_, NULL);
	_tmp8_ = _tmp7_;
	_tmp9_ = g_strconcat (_tmp8_, " ", NULL);
	_tmp10_ = _tmp9_;
	_tmp11_ = adjektive;
	_tmp11__length1 = adjektive_length1;
	_tmp12_ = adjektive;
	_tmp12__length1 = adjektive_length1;
	_tmp13_ = g_random_int_range ((gint32) 0, (gint32) _tmp12__length1);
	_tmp14_ = _tmp11_[_tmp13_];
	_tmp15_ = g_strconcat (_tmp10_, _tmp14_, NULL);
	_tmp16_ = _tmp15_;
	_tmp17_ = g_strconcat (_tmp16_, " ", NULL);
	_tmp18_ = _tmp17_;
	_tmp19_ = orte;
	_tmp19__length1 = orte_length1;
	_tmp20_ = orte;
	_tmp20__length1 = orte_length1;
	_tmp21_ = g_random_int_range ((gint32) 0, (gint32) _tmp20__length1);
	_tmp22_ = _tmp19_[_tmp21_];
	_tmp23_ = g_strconcat (_tmp18_, _tmp22_, NULL);
	_tmp24_ = _tmp23_;
	_tmp25_ = g_strconcat (_tmp24_, ".", NULL);
	_tmp26_ = _tmp25_;
	_g_free0 (_tmp24_);
	_g_free0 (_tmp18_);
	_g_free0 (_tmp16_);
	_g_free0 (_tmp10_);
	_g_free0 (_tmp8_);
	_g_free0 (_tmp2_);
	result = _tmp26_;
	return result;
}


void _vala_main (gchar** args, int args_length1) {
	gchar** vornamen_m = NULL;
	gint _tmp0_ = 0;
	gchar** _tmp1_ = NULL;
	gint vornamen_m_length1 = 0;
	gint _vornamen_m_size_ = 0;
	gchar** vornamen_w = NULL;
	gint _tmp2_ = 0;
	gchar** _tmp3_ = NULL;
	gint vornamen_w_length1 = 0;
	gint _vornamen_w_size_ = 0;
	gchar** verben = NULL;
	gint _tmp4_ = 0;
	gchar** _tmp5_ = NULL;
	gint verben_length1 = 0;
	gint _verben_size_ = 0;
	gchar** adjektive = NULL;
	gint _tmp6_ = 0;
	gchar** _tmp7_ = NULL;
	gint adjektive_length1 = 0;
	gint _adjektive_size_ = 0;
	gchar** orte = NULL;
	gint _tmp8_ = 0;
	gchar** _tmp9_ = NULL;
	gint orte_length1 = 0;
	gint _orte_size_ = 0;
	gint anzahl = 0;
	gchar** _tmp10_ = NULL;
	gint _tmp10__length1 = 0;
	setlocale (LC_ALL, "");
	_tmp1_ = lese ("../data/vornamen_m.txt", &_tmp0_);
	vornamen_m = _tmp1_;
	vornamen_m_length1 = _tmp0_;
	_vornamen_m_size_ = vornamen_m_length1;
	_tmp3_ = lese ("../data/vornamen_w.txt", &_tmp2_);
	vornamen_w = _tmp3_;
	vornamen_w_length1 = _tmp2_;
	_vornamen_w_size_ = vornamen_w_length1;
	_tmp5_ = lese ("../data/verben.txt", &_tmp4_);
	verben = _tmp5_;
	verben_length1 = _tmp4_;
	_verben_size_ = verben_length1;
	_tmp7_ = lese ("../data/adjektive.txt", &_tmp6_);
	adjektive = _tmp7_;
	adjektive_length1 = _tmp6_;
	_adjektive_size_ = adjektive_length1;
	_tmp9_ = lese ("../data/orte.txt", &_tmp8_);
	orte = _tmp9_;
	orte_length1 = _tmp8_;
	_orte_size_ = orte_length1;
	anzahl = 1;
	_tmp10_ = args;
	_tmp10__length1 = args_length1;
	if (_tmp10__length1 >= 2) {
		gchar** _tmp11_ = NULL;
		gint _tmp11__length1 = 0;
		const gchar* _tmp12_ = NULL;
		gint _tmp13_ = 0;
		_tmp11_ = args;
		_tmp11__length1 = args_length1;
		_tmp12_ = _tmp11_[1];
		_tmp13_ = atoi (_tmp12_);
		anzahl = _tmp13_;
	}
	{
		gint i = 0;
		i = 1;
		{
			gboolean _tmp14_ = FALSE;
			_tmp14_ = TRUE;
			while (TRUE) {
				gint _tmp16_ = 0;
				gchar* p = NULL;
				gchar** _tmp17_ = NULL;
				gint _tmp17__length1 = 0;
				gchar* _tmp18_ = NULL;
				const gchar* _tmp19_ = NULL;
				gchar** _tmp20_ = NULL;
				gint _tmp20__length1 = 0;
				gchar** _tmp21_ = NULL;
				gint _tmp21__length1 = 0;
				gchar** _tmp22_ = NULL;
				gint _tmp22__length1 = 0;
				gchar* _tmp23_ = NULL;
				gchar* _tmp24_ = NULL;
				if (!_tmp14_) {
					gint _tmp15_ = 0;
					_tmp15_ = i;
					i = _tmp15_ + 1;
				}
				_tmp14_ = FALSE;
				_tmp16_ = anzahl;
				if (!(i <= _tmp16_)) {
					break;
				}
				_tmp17_ = vornamen_m;
				_tmp17__length1 = vornamen_m_length1;
				_tmp18_ = person (_tmp17_, _tmp17__length1);
				p = _tmp18_;
				_tmp19_ = p;
				_tmp20_ = verben;
				_tmp20__length1 = verben_length1;
				_tmp21_ = adjektive;
				_tmp21__length1 = adjektive_length1;
				_tmp22_ = orte;
				_tmp22__length1 = orte_length1;
				_tmp23_ = satz (_tmp19_, _tmp20_, _tmp20__length1, _tmp21_, _tmp21__length1, _tmp22_, _tmp22__length1);
				_tmp24_ = _tmp23_;
				g_print ("%s\n", _tmp24_);
				_g_free0 (_tmp24_);
				_g_free0 (p);
			}
		}
	}
	orte = (_vala_array_free (orte, orte_length1, (GDestroyNotify) g_free), NULL);
	adjektive = (_vala_array_free (adjektive, adjektive_length1, (GDestroyNotify) g_free), NULL);
	verben = (_vala_array_free (verben, verben_length1, (GDestroyNotify) g_free), NULL);
	vornamen_w = (_vala_array_free (vornamen_w, vornamen_w_length1, (GDestroyNotify) g_free), NULL);
	vornamen_m = (_vala_array_free (vornamen_m, vornamen_m_length1, (GDestroyNotify) g_free), NULL);
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
	_vala_main (argv, argc);
	return 0;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



